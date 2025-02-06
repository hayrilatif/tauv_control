#ifndef STATE_H
#define STATE_H

#include <string>
#include <iostream>
#include "pybind11/pybind11.h"
#include <pybind11/stl.h>

class State
{
    public:
    std::string name;
    
    State(std::string name);

    virtual void on_enter() = 0; //global memory object pointer alacak
    virtual void handle_action() = 0; //global memory pointer alacak
    virtual void handle_transition() = 0; //global memory pointer alacak
    virtual void on_exit() = 0; //global memory pointer alacak

    virtual ~State();
};

struct PyState: public State
{
    public:
    using State::State;

    void on_enter() override {
        PYBIND11_OVERRIDE_PURE(
            void,
            State,
            on_enter
        );
    };

    void handle_action() override{
        PYBIND11_OVERRIDE_PURE(
            void,
            State,
            handle_action
        );
    };

    void handle_transition() override{
        PYBIND11_OVERRIDE_PURE(
            void,
            State,
            handle_transition
        );
    };

    void on_exit() override{
        PYBIND11_OVERRIDE_PURE(
            void,
            State,
            on_exit
        );
    };
};

#endif