import numpy as np
import os
import matplotlib.pyplot as plt

file = open("python_input.txt", "r")

# ignores the first word of every sentence
# data volume
ammount_of_data = int(file.readline().split()[1])

# heights
BST_height = int(file.readline().split()[1])
AVL_height = int(file.readline().split()[1])

# inserts
BST_comp_insert = int(file.readline().split()[1])
AVL_comp_insert = int(file.readline().split()[1])

# searchs
BST_comp_search = int(file.readline().split()[1])
AVL_comp_search = int(file.readline().split()[1])

# times
BST_time = int(file.readline().split()[1])
AVL_time = int(file.readline().split()[1])

file.close()

# setting x and y values
x = np.arange(2)
heights = [BST_height, AVL_height]
inserts = [BST_comp_insert, AVL_comp_insert]
searchs = [BST_comp_search, AVL_comp_search]
times = [BST_time, AVL_time]

# figure's settings
fig = plt.figure(1)
fig.canvas.set_window_title('BST and AVL comparison')
fig.suptitle("BST and AVL comparison")
colors = ['purple','orange']
plt.subplots_adjust(wspace=0.3, hspace = 0.35)

# subplot 1 - heights
sp_heights = plt.subplot(2, 2, 1)
plt.bar(x, heights, color=colors)
plt.xticks(x, ("BST", "AVL"))
plt.title('Heights')
plt.margins(y=0.13)
plt.text(0,heights[0], heights[0], color='purple', fontweight='bold',
         horizontalalignment='center', verticalalignment='bottom')
plt.text(1,heights[1], heights[1], color='orange', fontweight='bold',
         horizontalalignment='center', verticalalignment='bottom')

# subplot 2 - times
sp_times = plt.subplot(2, 2, 2)
plt.bar(x, times, color=colors)
plt.xticks(x, ("BST", "AVL"))
plt.title('Time (ms)')
plt.margins(y=0.13)
plt.text(0,times[0], times[0], color='purple', fontweight='bold',
         horizontalalignment='center', verticalalignment='bottom')
plt.text(1,times[1], times[1], color='orange', fontweight='bold',
         horizontalalignment='center', verticalalignment='bottom')

# subplot 3 - insert
sp_inserts = plt.subplot(2, 2, 3)
plt.bar(x, inserts, color=colors)
plt.xticks(x, ("BST", "AVL"))
plt.title('Insert')
plt.margins(y=0.13)
plt.text(0,inserts[0], inserts[0], color='purple', fontweight='bold',
         horizontalalignment='center', verticalalignment='bottom')
plt.text(1,inserts[1], inserts[1], color='orange', fontweight='bold',
         horizontalalignment='center', verticalalignment='bottom')

# subplot 4 - searchs
sp_searchs = plt.subplot(2, 2, 4, sharey=sp_inserts)
plt.bar(x, searchs, color=colors)
plt.xticks(x, ("BST", "AVL"))
plt.setp(sp_searchs.get_yticklabels(), visible=False)
plt.title('Search')
plt.margins(y=0.13)
plt.text(0,searchs[0], searchs[0], color='purple', fontweight='bold',
         horizontalalignment='center', verticalalignment='bottom')
plt.text(1,searchs[1], searchs[1], color='orange', fontweight='bold',
         horizontalalignment='center', verticalalignment='bottom')

# saving the picture, then opening it
fig.savefig('comparison_plot.png')
os.system('comparison_plot.png')
