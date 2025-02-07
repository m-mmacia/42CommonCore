NAME = inception

INIT = sh srcs/requirements/tools/init.sh

all:
	@echo "Building images..."
	@mkdir -p /home/user/data/wp
	@mkdir -p /home/user/data/adminer
	@mkdir -p /home/user/data/db
	@mkdir -p /home/user/data/portainer
	@docker-compose -p $(NAME) -f srcs/docker-compose.yml up -d
	@clear
	@echo " . mmacia.42.fr -> wordpress"
	@echo " . adminer.mmacia.42.fr -> adminer"
	@echo " . portainer.mmacia.42.fr -> portainer"
	@echo " . portfolio.mmacia.42.fr -> site_static"

clean:
	@echo "Removing containers..."
	docker-compose -p $(NAME) -f srcs/docker-compose.yml down

fclean: clean
	@echo "Full cleaning..."
	@sudo rm -rf /home/$(USER)/data
	@docker builder prune -a -f
	docker-compose -p $(NAME) -f srcs/docker-compose.yml down -v --remove-orphans
	@rm -rf /home/user/data/*

re: fclean all

.PHONY: build all re clean fclean
