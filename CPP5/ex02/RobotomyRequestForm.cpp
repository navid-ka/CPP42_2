
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45) {
    _target = target;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy)
    : AForm(cpy.getName(), cpy.getGradeSign(), cpy.getGradeReq()) {
    _target = cpy._target;
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
    if (this != &rhs) {
        _target = rhs._target;
        AForm::operator=(rhs);
    }
    return (*this);
}

void RobotomyRequestForm::executeForm() const {
    srand(time(0));
    int randi = rand();

    if (randi % 50 == 0) {
        std::cout << _target << " has been robotomized" << std::endl;
    } else {
        std::cout << _target << " robotomization failed";
    }
}
