from ortools.algorithms.python import knapsack_solver
import os, random, time

def main(path_in, path_out):
    
    # Create the solver.
    solver = knapsack_solver.KnapsackSolver(
        knapsack_solver.SolverType.KNAPSACK_MULTIDIMENSION_BRANCH_AND_BOUND_SOLVER,
        "KnapsackExample",
    )

    values, weights = [], [[]]

    file_path = path_in
    with open(file_path, 'r') as file:
        lines = file.readlines()
        items, capacity = int(lines[1]), int(lines[2])
        print(items, capacity, '\n')
    
        for line in lines[4:]:
            line = line.split()
            v, w = int(line[0]), int(line[1])
            values.append(v)
            weights[0].append(w)

    capacities = [capacity]

    TIME_LIMIT = 180.0

    solver.set_time_limit(TIME_LIMIT)
    solver.init(values, weights, capacities)

    s = time.time()
    computed_value = solver.solve()
    e = time.time()

    packed_items = []
    packed_weights = []
    total_weight = 0
    
    file_path = path_out
    with open(file_path, 'a') as file:
        file.write(path_in + '\n')
        file.write("e - s = " + str(e-s) + '\n')
        file.write("e - s <= " + str(TIME_LIMIT-10.0) + ": " + str(e-s<=TIME_LIMIT-10.0) + '\n')
        file.write("Capacity = " + str(capacity) + '\n')
        file.write("Total value = " + str(computed_value) + '\n')
        for i in range(len(values)):
            if solver.best_solution_contains(i):
                packed_items.append(i)
                packed_weights.append(weights[0][i])
                total_weight += weights[0][i]
        file.write("Total weight: " + str(total_weight) + '\n')
        file.write("Packed items: " + str(packed_items) + '\n')
        file.write("Packed_weights: " + str(packed_weights) + '\n')
        file.write("================================================================================================\n")

if __name__ == "__main__":

    group_name = [
        "00Uncorrelated",
        "01WeaklyCorrelated",
        "02StronglyCorrelated",
        "03InverseStronglyCorrelated",
        "04AlmostStronglyCorrelated",
        "05SubsetSum",
        "06UncorrelatedWithSimilarWeights",
        "07SpannerUncorrelated",
        "08SpannerWeaklyCorrelated",
        "09SpannerStronglyCorrelated",
        "10MultipleStronglyCorrelated",
        "11ProfitCeiling",
        "12Circle"
    ]

    subgroup = [50,100,200,500,1000,2000,5000,10000]

    number_of_groups = len(group_name)
    number_of_subgroups = len(subgroup)

    for group in range(number_of_groups):
        for num in range(number_of_subgroups):
            n = str(subgroup[num])
            rand_s = str(random.randint(0,99))

            n, rand_s = n.zfill(5), rand_s.zfill(3)

            path_in = "D:\\kplib\\{}\\n{}\\R10000\\s{}.kp".format(
                group_name[group], n, rand_s
            )

            print(path_in, '\n')
            path_out = "D:\\kplib\\{}.txt".format(
                group_name[group]
            )

            main(path_in, path_out)

    print("DONE DONE DONE DONE DONE DONE DONE DONE DONE DONE")