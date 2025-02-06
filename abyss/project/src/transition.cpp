#include "transition.h"
#include "state.h"
#include <pybind11/stl.h>
#include <pybind11/pybind11.h>
#include <memory>

Transition::Transition(std::shared_ptr<State> from_state, std::shared_ptr<State> to_state)
    : from_state(from_state), to_state(to_state) {}

Transition::~Transition() {}