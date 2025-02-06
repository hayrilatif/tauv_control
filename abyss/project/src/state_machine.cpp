#include <string>
#include <iostream>
#include "state.h"
#include "transition.h"
#include "state_machine.h"
#include <pybind11/stl.h>

StateMachine::StateMachine(std::string name) : State(name) {}

StateMachine::~StateMachine() {}

void StateMachine::add_state(std::shared_ptr<State> state)
{
    states.push_back(state);
}

void StateMachine::add_transition(std::shared_ptr<Transition> transition)
{
    transitions.push_back(transition);
}

void StateMachine::set_initial_state(std::shared_ptr<State> state)
{
    current_state = state;
}

void StateMachine::on_enter() //global mem alacak
{
    if (current_state != nullptr)
    {
        current_state -> on_enter();
    }
}

void StateMachine::handle_action() //global mem alacak
{
    if (current_state != nullptr)
    {
        current_state -> handle_action(); //global mem ver
    }
}

void StateMachine::handle_transition() //global mem alacak
{
    if (current_state == nullptr)
    {
        return;
    }

    current_state -> handle_action(); //glob mem ver

    //gecis kontrolu
    for (std::shared_ptr<Transition> transition : this -> transitions)
    {
        if (transition -> from_state != current_state)
        {
            continue;
        }

        if (transition -> check_condition())
        {
            switch_state(transition -> to_state); //+ glob mem
            break;
        }
    }
    
}

void StateMachine::on_exit() //global mem alacak
{
    if (current_state == nullptr)
    {
        return;
    }

    current_state -> on_exit();
}

void StateMachine::switch_state(std::shared_ptr<State> new_state) //glob mem yine ver
{
    current_state -> on_exit();
    current_state = new_state;
    current_state -> on_enter();
}

std::shared_ptr<State> StateMachine::get_current_state() //glob mem yine ver
{
    return current_state;
}