# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyudi <yyudi@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/03 10:21:30 by yyudi             #+#    #+#              #
#    Updated: 2025/10/03 10:21:31 by yyudi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME    := accounts
CXX     := c++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98

SRCS    := Account.cpp tests.cpp
OBJS    := $(SRCS:.cpp=.o)
DEPS    := Account.hpp

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
