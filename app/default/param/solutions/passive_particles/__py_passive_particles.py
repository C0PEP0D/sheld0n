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
    # initialize output
    initial_particles_position = np.empty(shape=(particle_number, particle_state_size))
    # set random initial positions to all particles
    for particle_index in range(particle_number):
        initial_particles_position[particle_index, :] = np.random.default_rng().uniform(-np.pi, np.pi, size=(1, particle_state_size))
    # return output
    return initial_particles_position.flatten()

# input:
#   state: state variable that groups the state variables of all particles
#   particle_state_size: dimension of the state variable of one particle
#   particle_number: number of particle
# output:
#   dictionary that contains the post processed data
def post(state, particle_state_size, particle_number):
    # initialize output
    post_processing = {}
    # post process the position of each particle
    particles_state = state.reshape((particle_number, particle_state_size))
    for particle_index in range(particle_number):
        post_processing["passive_particles__index_{:0>{}d}__pos_0".format(particle_index, particle_number//10 + 1)] = particles_state[particle_index, 0]
        post_processing["passive_particles__index_{:0>{}d}__pos_1".format(particle_index, particle_number//10 + 1)] = particles_state[particle_index, 1]
    # return output
    return post_processing
