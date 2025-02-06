#include <memory>
#include "pybind11/pybind11.h"
#include "state.h"
#include "state_machine.h"
#include "transition.h"

namespace py = pybind11;

//modül tanimi
PYBIND11_MODULE(core, m) {
    m.doc() = "abyss, TAUV vehicle navigation, mapping and smart decision taking system.";

    py::class_<State, PyState, std::shared_ptr<State>>(m, "State")
        .def(py::init<std::string>())
        .def_readwrite("name", &State::name);
    
    py::class_<Transition, PyTransition, std::shared_ptr<Transition>>(m, "Transition")
        .def(py::init<std::shared_ptr<State>, std::shared_ptr<State>>()) //def const
        .def(py::init<std::shared_ptr<StateMachine>, std::shared_ptr<StateMachine>>()); //def const


    py::class_<StateMachine, State, std::shared_ptr<StateMachine>>(m, "StateMachine")
        .def(py::init<std::string>()) //def const like
        .def("add_state",&StateMachine::add_state)
        .def("add_transition",&StateMachine::add_transition)
        .def("handle_transition", &StateMachine::handle_transition)
        .def("set_initial_state", &StateMachine::set_initial_state)
        .def_property_readonly("get_current_state", &StateMachine::get_current_state);
}
