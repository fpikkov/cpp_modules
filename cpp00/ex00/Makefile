# --------	MAKE VARIABLES	--------
RED = \033[1;31m
GREEN = \033[1;32m
CYAN = \033[1;36m
CLEAR = \033[0m

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = megaphone

BUILD = ${NAME}

SRCS =	megaphone.cpp

OBJS = ${SRCS:.cpp=.o}

# --------	MAKE TARGETS	--------
all: ${BUILD}

${BUILD}: ${OBJS}
	@echo "${GREEN}Generating build...${CLEAR}"
	${CXX} ${CXXFLAGS} -o $@ $^

${OBJS}: %.o : %.cpp
	@echo "${CYAN}Generating object files...${CLEAR}"
	@$(CXX) $(CXXFLAGS) -c $<

clean:
	@echo "${RED}Cleaning object files...${CLEAR}"
	@rm -rf *.o

fclean: clean
	@echo "${RED}Fully cleaning project...${CLEAR}"
	@rm -rf ${NAME}

re: fclean all

.PHONY: all re clean fclean
