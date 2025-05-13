# --------	MAKE VARIABLES	--------
RED = \033[1;31m
GREEN = \033[1;32m
CYAN = \033[1;36m
CLEAR = \033[0m

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
INC_FLAGS = -I {INCLUDES}

NAME = animal

BUILD = ${NAME}

INCLUDES = Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp
SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp

OBJS = ${SRCS:.cpp=.o}

# --------	MAKE TARGETS	--------
all: ${BUILD}

${BUILD}: ${OBJS}
	@echo "${GREEN}Generating build...${CLEAR}"
	@${CXX} ${CXXFLAGS} -o $@ $^
	@echo "${GREEN}Executable ${CYAN}"${NAME}"${GREEN} was created${CLEAR}"

${OBJS}: %.o : %.cpp
	@echo "${CYAN}Generating object files...${CLEAR}"
	@$(CXX) $(CXXFLAGS) -c $< ${INC_FLAGS}

clean:
	@echo "${RED}Cleaning object files...${CLEAR}"
	@rm -rf *.o

fclean: clean
	@echo "${RED}Fully cleaning project...${CLEAR}"
	@rm -rf ${NAME}

re: fclean all

.PHONY: all re clean fclean
