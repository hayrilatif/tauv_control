import abyss.core as core
import random

#durumlar tanımlanır
class IdleState(core.State):
    def handle_action(self):
        print("Idle")

class MovingState(core.State):
    def handle_action(self):
        print("Moving")

class ScanningState(core.State):
    def handle_action(self):
        print("Scannng")


def run_demo():
    
    state1 = IdleState("Idle")
    state2 = MovingState("Move")
    state3 = ScanningState("Scan")
    
    # durum makinesine durumlar eklenir
    sm = core.StateMachine("AUV State Machine")
    sm.add_state(state1)
    sm.add_state(state2)
    sm.add_state(state3)
    sm.set_initial_state(state1)
    
    print("Başlangıç durumu:", sm.get_current_state.name)
    
    # geçişler durum makşnesne eklenir. geçişler de tanımlanıyor durumlar gibi ama üşendim
    transition1 = core.Transition(state1, state2) #transition base sınıfı default hep false veriyor check conditionı
    transition2 = core.Transition(state2, state3)
    transition3 = core.Transition(state3, state1)
    
    sm.add_transition(transition1)
    sm.add_transition(transition2)
    sm.add_transition(transition3)

    # durum makinesi handle transition transition.cpp içinde tanimli
    sm.handle_transition()
    print("Şu anki durum:", sm.get_current_state.name)
    
    sm.handle_transition()
    print("Şu anki durum:", sm.get_current_state.name)
    
    sm.handle_transition()
    print("Şu anki durum:", sm.get_current_state.name)
    
if __name__ == "__main__":
    run_demo()
