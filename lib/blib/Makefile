##
## EPITECH PROJECT, 2020
## Base
## File description:
## Main Makefile
##

#################### PATH #####################
PATH_BLIB		=	lib/blib

PATH_LINKED_LIST	=	lib/linked_list


################# COMPILATION #################
all:
	make -C	$(PATH_BLIB)
	make -C	$(PATH_LINKED_LIST)

re:	fclean all

clean:
	@(make clean -C $(PATH_BLIB)) > /dev/null
	@(make clean -C $(PATH_LINKED_LIST)) > /dev/null

fclean:	clean
	@(make fclean -C $(PATH_BLIB)) > /dev/null
	@(make fclean -C $(PATH_LINKED_LIST)) > /dev/null
