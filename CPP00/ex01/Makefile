# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/03 10:20:08 by yyudi             #+#    #+#              #
#    Updated: 2025/10/03 10:20:09 by yyudi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ex01/Makefile
NAME    := phonebook
CXX     := c++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98

SRCS    := main.cpp Contact.cpp PhoneBook.cpp
OBJS    := $(SRCS:.cpp=.o)
DEPS    := Contact.hpp PhoneBook.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
