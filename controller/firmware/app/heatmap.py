import matplotlib.pyplot as plt
import matplotlib.patches as patches

def read_file(filename):
    with open(filename, 'r') as f:
        return f.read()

# Asking user for filename and reading the data from it
filename = input("Enter the filename containing the data: ")
data = read_file(filename)

# Extracting the traditional McCabe cyclomatic complexity and filenames
complexities = []
function_names = []

for line in data.strip().split("\n")[1:]:  # Start from 1 to skip header
    parts = line.split("\t")
    if len(parts) < 5:  # Checking if there are enough parts in the line
        print(f"Skipping line: {line}")
        continue
    complexity = int(parts[2])  # Third column
    function_name = parts[4].split(":")[-1].strip()  # Extracting the function name from the last column
    complexities.append(complexity)
    function_names.append(function_name)

# Get unique complexities and their count
complexities_count = dict((x,complexities.count(x)) for x in set(complexities))

# Set up figure and axis
fig, ax = plt.subplots(figsize=(10, len(function_names) * 0.5))

# Define the size of the square and the spacing
size = 0.4
spacing = 0.5

# Iterate through the functions and plot squares
for i, function in enumerate(function_names):
    y_coord = i * (size + spacing)

    # The x_coord will be based on the complexity of the function.
    x_coord = complexities_count[complexities[i]] * size + complexities_count[complexities[i]] * spacing

    # Create a rectangle (square) with the function's corresponding complexity color
    rect = patches.Rectangle((x_coord, y_coord), size, size, facecolor=plt.cm.YlGnBu(complexities[i]/10)) # Adjust the colormap as needed
    ax.add_patch(rect)

    # Annotate the square with the function name
    ax.text(x_coord + size/2, y_coord + size/2, function, ha='center', va='center', fontsize=8)

# Set axis properties
ax.set_xlim(0, max(complexities_count.values()) * size + max(complexities_count.values()) * spacing)
ax.set_ylim(0, len(function_names) * (size + spacing))
ax.axis('off')  # Turn off the axis

plt.tight_layout()
plt.show()
