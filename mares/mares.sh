#!/bin/sh

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    mares.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgaia <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/20 21:54:56 by rgaia             #+#    #+#              #
#    Updated: 2019/04/20 21:56:41 by rgaia            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#run manger
./manger &

sleep 10

kill -s KILL $(pgrep crap lampon ruins xanthos yes)
kill -s KILL $(top -l 1 | grep manger | awk '{print $1}')

rm -rf *.poo

sleep 5

#run my own horsies
./my_horse &

