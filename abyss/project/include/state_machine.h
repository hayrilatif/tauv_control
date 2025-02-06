#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <string>
#include <iostream>
#include <list>
#include "state.h"
#include "transition.h"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

class StateMachine: public State
{
    public:
    StateMachine(std::string name);

    void add_state(std::shared_ptr<State> state);
    void add_transition(std::shared_ptr<Transition> transition);
    void set_initial_state(std::shared_ptr<State> state);

    void on_enter() override; //global mem alacak
    void handle_action() override;
    void handle_transition() override;
    void on_exit() override;

    std::shared_ptr<State> get_current_state();

    virtual ~StateMachine();

    private:
    std::list<std::shared_ptr<State>> states;
    std::list<std::shared_ptr<Transition>> transitions;
    std::shared_ptr<State> current_state;

    void switch_state(std::shared_ptr<State> new_state); //+ glob mem verece
};

#endif