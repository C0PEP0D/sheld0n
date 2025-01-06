import numpy as np

# input:
#   x: particle position
#   u: flow velocity at the particle position
# output:
#   dx: temporal derivative of the particle position
def position_temporal_derivative(x, u):
    return u

# input:
#   particle_state_size: dimension of the state variable of one particle
#   particle_number: number of particle
# output:
#   initial particle state
def init(particle_state_size, particle_number):
    initial_particles_position = np.empty(shape=(particle_number, particle_state_size))
    for particle_index in range(particle_number):
        initial_particles_position[particle_index, :] = np.random.default_rng().uniform(-np.pi, np.pi, shape=(1, particle_state_size))
    return initial_particles_position.flatten()
