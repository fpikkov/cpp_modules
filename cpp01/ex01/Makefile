# --------	MAKE VARIABLES	--------
RED = \033[1;31m
GREEN = \033[1;32m
CYAN = \033[1;36m
CLEAR = \033[0m

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
DBGFLAGS = -DDEBUG=1
INC_FLAGS = -I {INCLUDES}

NAME = horde

BUILD = ${NAME}

INCLUDES = Zombie.hpp
SRCS = main.cpp Zombie.cpp zombieHorde.cpp

OBJS = ${patsubst ${SRC_DIR}/%.c,${OBJ_DIR}/%.o,${SRCS}}

# --------	MAKE TARGETS	--------
all: ${BUILD}

${BUILD}: ${OBJS}
	@echo "${GREEN}Generating build...${CLEAR}"
	@${CXX} ${CXXFLAGS} -o $@ $^
	@echo "${GREEN}Executable ${CYAN}"${NAME}"${GREEN} was created${CLEAR}"

${OBJ_DIR}/%.o : ${SRC_DIR}/%.c
	@echo "${CYAN}Generating object files...${CLEAR}"
	@$(CXX) $(CXXFLAGS) -c $< -o $@ ${INC_FLAGS}

clean:
	@echo "${RED}Cleaning object files...${CLEAR}"
	@rm -rf *.o

fclean: clean
	@echo "${RED}Fully cleaning project...${CLEAR}"
	@rm -rf ${NAME}

debug: CXXFLAGS += ${DBGFLAGS}
debug: fclean ${BUILD}

re: fclean all

.PHONY: all re clean fclean debug
