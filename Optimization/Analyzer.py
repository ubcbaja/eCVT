# -*- coding: utf-8 -*-
"""
Created on Wed Jan 15 21:30:23 2020

@author: Safet
"""

import Reward_Func_Error as ErrorReward

import ga
from pso import pso # access from pip install broken

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.patches as patches
from matplotlib import cm 
from mpl_toolkits import mplot3d
import seaborn as sns
import time
import datetime
import sys
#%%

sns.set_style("whitegrid")
sns.set_palette("muted")

x = np.linspace(0, 3, 100)
y = np.zeros(len(x))

for i, val in enumerate(x):
    y[i] = ErrorReward.GetReward(val)

ax = sns.scatterplot(x, y, hue = y, legend = None)
ax.set_title("Error Reward Function")
ax.set_xlabel("Raw value")
ax.set_ylabel("Reward")

#%% PSO Test

# Use 2D Rastrigin as performance test
def rastrigin(z):
    x = z[0]
    y = z[1]
    return 20 + (x**2 - 10*np.cos(2*np.pi*x)) + (y**2 - 10*np.cos(2*np.pi*y))

lowBound = [-10, -10]
upBound = [10, 10]

xOpt, fOpt = pso(rastrigin, lowBound, upBound, swarmsize=10, maxiter=100)

print("Optimal vals found at: " + str(xOpt) + ", " + str(fOpt))

#%% Graph Rastrigin
# X = np.linspace(-5.12, 5.12, 100)     
# Y = np.linspace(-5.12, 5.12, 100)     
# X, Y = np.meshgrid(X, Y) 

# Z = (X**2 - 10 * np.cos(2 * np.pi * X)) + \
#   (Y**2 - 10 * np.cos(2 * np.pi * Y)) + 20
 
# fig = plt.figure() 
# ax = fig.gca(projection='3d') 
# ax.plot_surface(X, Y, Z, rstride=1, cstride=1,
#   cmap=cm.nipy_spectral, linewidth=0.08,
#   antialiased=True)    
# ax.scatter(xOpt[0], xOpt[1], 0, s=14, c="red")
# # plt.savefig('rastrigin_graph.png')
# plt.show()

#%% GA Test
# """
# The y=target is to maximize this equation:
#     y = w1x1+w2x2+w3x3+w4x4+w5x5+6wx6
#     where (x1,x2,x3,x4,x5,x6)=(4,-2,3.5,5,-11,-4.7)
#     What are the best values for the 6 weights w1 to w6?
#     We are going to use the genetic algorithm for the best possible values after a number of generations.
# """

# # Inputs of the equation.
# # equation_inputs = [4,-2,3.5,5,-11,-4.7]
# equation_inputs = [2, 4]

# # Number of the weights we are looking to optimize.
# num_weights = len(equation_inputs)

# """
# Genetic algorithm parameters:
#     Mating pool size
#     Population size
# """
# sol_per_pop = 8
# num_parents_mating = 4

# # Defining the population size.
# pop_size = (sol_per_pop,num_weights) # The population will have sol_per_pop chromosome where each chromosome has num_weights genes.
# #Creating the initial population.
# new_population = np.random.uniform(low=-4.0, high=4.0, size=pop_size)
# print(new_population)

# """
# new_population[0, :] = [2.4,  0.7, 8, -2,   5,   1.1]
# new_population[1, :] = [-0.4, 2.7, 5, -1,   7,   0.1]
# new_population[2, :] = [-1,   2,   2, -3,   2,   0.9]
# new_population[3, :] = [4,    7,   12, 6.1, 1.4, -4]
# new_population[4, :] = [3.1,  4,   0,  2.4, 4.8,  0]
# new_population[5, :] = [-2,   3,   -7, 6,   3,    3]
# """

# best_outputs = []
# num_generations = 1000
# for generation in range(num_generations):
#     print("Generation : ", generation)
#     # Measuring the fitness of each chromosome in the population.
#     fitness = ga.cal_pop_fitness(equation_inputs, new_population)
#     print("Fitness")
#     print(fitness)

#     best_outputs.append(np.max(np.sum(new_population*equation_inputs, axis=1)))
#     # The best result in the current iteration.
#     print("Best result : ", np.max(np.sum(new_population*equation_inputs, axis=1)))
    
#     # Selecting the best parents in the population for mating.
#     parents = ga.select_mating_pool(new_population, fitness, 
#                                       num_parents_mating)
#     print("Parents")
#     print(parents)

#     # Generating next generation using crossover.
#     offspring_crossover = ga.crossover(parents,
#                                        offspring_size=(pop_size[0]-parents.shape[0], num_weights))
#     print("Crossover")
#     print(offspring_crossover)

#     # Adding some variations to the offspring using mutation.
#     offspring_mutation = ga.mutation(offspring_crossover, num_mutations=2)
#     print("Mutation")
#     print(offspring_mutation)

#     # Creating the new population based on the parents and offspring.
#     new_population[0:parents.shape[0], :] = parents
#     new_population[parents.shape[0]:, :] = offspring_mutation
    
# # Getting the best solution after iterating finishing all generations.
# #At first, the fitness is calculated for each solution in the final generation.
# fitness = ga.cal_pop_fitness(equation_inputs, new_population)
# # Then return the index of that solution corresponding to the best fitness.
# best_match_idx = np.where(fitness == np.max(fitness))

# print("Best solution : ", new_population[best_match_idx, :])
# print("Best solution fitness : ", fitness[best_match_idx])


# plt.plot(best_outputs)
# plt.xlabel("Iteration")
# plt.ylabel("Fitness")
# plt.show()