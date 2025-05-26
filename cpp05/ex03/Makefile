# --------	MAKE VARIABLES	--------
RED = \033[1;31m
GREEN = \033[1;32m
CYAN = \033[1;36m
CLEAR = \033[0m

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11 -g
INC_FLAGS = -I {INCLUDES}

NAME = intern

BUILD = ${NAME}

INCLUDES = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp
SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

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
	@rm -f *_shrubbery

fclean: clean
	@echo "${RED}Fully cleaning project...${CLEAR}"
	@rm -rf ${NAME}

re: fclean all

.PHONY: all re clean fclean
