# NOTE: DEBUG program

import subprocess
import random

# Generate a random sequence
size = random.randint(10, 20)  # random size between 10 and 100
sequence = [random.randint(0, 1000) for _ in range(size)]
sequence_str = ' '.join(map(str, sequence))

# Run the executable, passing the sequence as an argument
result = subprocess.run(['./PmergeMe', sequence_str], capture_output=True, text=True)
output = result.stdout

# Find the line starting with "After: "
# for line in output.splitlines():
#     if line.startswith("After: "):
#         output_sequence = list(map(int, line[len("After: "):].split()))
#         break
# else:
#     output_sequence = []

for line in output.splitlines():
    if line.startswith("After vector: "):
        output_sequence = list(map(int, line[len("After vector: "):].split()))
        break
else:
    output_sequence = []

for line in output.splitlines():
    if line.startswith("After list: "):
        output_sequence_list = list(map(int, line[len("After list: "):].split()))
        break
else:
    output_sequence_list = []

# Check if the output sequence is sorted
is_sorted = all(output_sequence[i] <= output_sequence[i+1] for i in range(len(output_sequence)-1))
is_sorted_list = all(output_sequence_list[i] <= output_sequence_list[i+1] for i in range(len(output_sequence_list)-1))


print("Input:", ' '.join(map(str, sequence)))
print("Vector output:", ' '.join(map(str, output_sequence)))
print("List   output:", ' '.join(map(str, output_sequence_list)))
print("Vector sorted:", is_sorted)
print("List   sorted:", is_sorted_list)
