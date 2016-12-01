# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niborrel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/07 21:08:29 by niborrel          #+#    #+#              #
#    Updated: 2016/10/09 21:51:38 by rbaum            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.PHONY:			all clean fclean re

GRN="\033[0;32m"
YEL="\033[0;33m"
BLU="\033[0;34m"
RED="\033[0;35m"
NC="\033[0m"

ASM_PATH	= 		./asm_dir

VM_PATH 	=		./corewar_dir


ASM		 	= 		./asm_dir/asm

VM		 	= 		./corewar_dir/corewar

LOCAL_ASM	= ./asm

LOCAL_VM	= ./corewar

PRINT		= echo

all: asm corewar

asm:
	@make -C $(ASM_PATH)
	@ln -sf $(ASM) $(LOCAL_ASM)
	@$(PRINT) $(GRN) "[ln -sf] asm"  $(NC)

corewar:
	@make -C $(VM_PATH)
	@ln -sf $(VM) $(LOCAL_VM)
	@$(PRINT) $(GRN) "[ln -sf] VM" $(NC)

clean:
	@make -C $(ASM_PATH) clean
	@make -C $(VM_PATH)	clean

fclean:
	@make -C $(ASM_PATH) fclean
	@make -C $(VM_PATH)	fclean
	@rm -f $(LOCAL_ASM)
	@rm -f $(LOCAL_VM)

re: fclean all