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
for line in output.splitlines():
    if line.startswith("After: "):
        output_sequence = list(map(int, line[len("After: "):].split()))
        break
else:
    output_sequence = []

# Check if the output sequence is sorted
is_sorted = all(output_sequence[i] <= output_sequence[i+1] for i in range(len(output_sequence)-1))

print("Input:", ' '.join(map(str, sequence)))
print("Output:", ' '.join(map(str, output_sequence)))
print("Sorted:", is_sorted)
