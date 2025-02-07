#!/bin/bash

if [ -f "/var/www/html/wordpress/wp-config.php" ]; then
    echo "WordPress is already installed in this directory."
    exec "$@"
    exit 0
fi

if [ ! -f "/usr/local/bin/wp" ]; then
    cd /tmp
    curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
    chmod +x wp-cli.phar
    mv wp-cli.phar /usr/local/bin/wp
fi

if [ ! -d "/var/www/html/wordpress" ]; then
    mkdir -p /var/www/html/wordpress
fi

chmod -R 755 /var/www/html/wordpress
chown -R www-data:www-data /var/www/html/wordpress

cd /var/www/html/wordpress
wp core download --allow-root --path=/var/www/html/wordpress

echo "Generating WordPress 'wp-config.php'..."
wp config create --allow-root --dbname=${WP_DB_NAME} --dbuser=${DB_USER} --dbpass=${DB_PASSWD} --dbhost=${WP_HOST}

echo "Installing WordPress deps..."
wp core install --allow-root --url=${WP_URL} --title=${WP_TITLE} --admin_user=${WP_ADMIN} --admin_password=${WP_ADMIN_PASSWD} --admin_email=${WP_ADMIN_EMAIL}

wp plugin install redis-cache --activate --allow-root --path=/var/www/html/wordpress
wp plugin list --allow-root --path=/var/www/html/wordpress

echo "Creating users..."
if ! wp user get ${WP_ADMIN} --path=/var/www/html/wordpress --allow-root; then
    wp user create ${WP_ADMIN} ${WP_ADMIN_EMAIL} --role=administrator --user_pass=${WP_ADMIN_PASSWD} --path=/var/www/html/wordpress --allow-root
fi

if ! wp user get ${WP_USER} --path=/var/www/html/wordpress --allow-root; then
    wp user create ${WP_USER} ${WP_MAIL} --role=editor --user_pass=${WP_PASSWD} --path=/var/www/html/wordpress --allow-root
fi

exec "$@"
