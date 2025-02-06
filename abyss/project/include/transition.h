#ifndef TRANSITION_H
#define TRANSITION_H

#include <string>
#include <iostream>
#include "state.h"
#include <memory>
#include "pybind11/pybind11.h"
#include <pybind11/stl.h>

namespace py = pybind11;

class Transition
{
    public:

    std::shared_ptr<State> from_state, to_state;

    Transition(std::shared_ptr<State> from_state, std::shared_ptr<State> to_state);
    
    std::string name;

    virtual bool check_condition() { return false; } //global memory pointer alacak

    virtual ~Transition();
};

class PyTransition : public Transition
{
    public:
    using Transition::Transition;

    bool check_condition() override {
        PYBIND11_OVERRIDE(
            bool,
            Transition,
            check_condition
        );
    }; //global memory pointer alacak

};



////////////lambda transition yazilacak pythondan direkt transition condition fonksiyonu alinacak




#endif