from brian2 import *
from models import StructuralPlasticityModel
model = StructuralPlasticityModel(
    order=250, 
    V_th=19.9*mV, 
    delta_T_s=1*second, 
    g=4, 
    tau_ca=5*second,
    enable_plasticity=True
    )

model.run(800*second)