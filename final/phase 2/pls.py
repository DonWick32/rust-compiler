class DAGNode:
    def __init__(self, op, left=None, right=None):
        self.op = op
        self.left = left
        self.right = right
        self.parents = []
        self.children = []

    def add_child(self, child):
        self.children.append(child)
        child.parents.append(self)

def generate_dag(tac):
    dag = {}
    for line in tac:
        parts = line.split(' ')
        op = parts[3] if len(parts) >= 4 else None
        if op == '<':
            op = 'read'
        elif op == '>':
            op = 'write'
        elif op == '=':
            op = 'assign'
        elif op == '+':
            op = 'add'
        elif op == '-':
            op = 'sub'
        elif op == '*':
            op = 'mul'
        elif op == '/':
            op = 'div'
        else:
            op = 'other'

        left = parts[0] if len(parts) >= 1 else None
        if left and left not in dag:
            dag[left] = DAGNode(left)
        if op != 'assign':
            right = parts[4] if len(parts) >= 5 else None
            if right and right not in dag:
                dag[right] = DAGNode(right)
            node = DAGNode(op, dag[left], dag[right] if right else None)
        else:
            right = parts[4] if len(parts) >= 5 else None
            if right and right not in dag:
                dag[right] = DAGNode(right)
            node = DAGNode(op, dag[right])
        if left:
            dag[left] = node
    return dag

def identify_basic_blocks(tac):
    basic_blocks = []
    current_block = []
    for line in tac:
        current_block.append(line)
        if line.startswith('goto') or line.startswith('if'):
            basic_blocks.append(current_block)
            current_block = []
    if current_block:
        basic_blocks.append(current_block)
    return basic_blocks

def construct_cfg(basic_blocks):
    label_to_line = {}
    cfg = {}
    for i, block in enumerate(basic_blocks):
        last_line = block[-1]
        if last_line.startswith('goto'):
            target_label = last_line.split(' ')[1]
            target = int(target_label[1:])  # Remove the prefix before converting to integer
            cfg[i] = [target]
        elif last_line.startswith('if'):
            target_label = last_line.split(' ')[-1]
            target = int(target_label[1:])  # Remove the prefix before converting to integer
            cfg[i] = [i + 1, target]
        else:
            if i < len(basic_blocks) - 1:
                cfg[i] = [i + 1]
            else:
                cfg[i] = []
        # Map labels to line numbers
        for line in block:
            if line.startswith(('goto', 'if')):
                label = line.split(' ')[-1]
                if label not in label_to_line:
                    label_to_line[label] = len(label_to_line) + 1
    return cfg

def print_dag(dag):
    for key, node in dag.items():
        print("Node:", key)
        print("Operation:", node.op)
        print("Children:", [child.op for child in node.children])
        print("Parents:", [parent.op for parent in node.parents])
        print()

def print_cfg(cfg):
    for key, value in cfg.items():
        print("Block", key, ":", value)

# Example TAC
tac = [
    "t0 = low < high",
    "t1 = not t0",
    "if t1 goto L1",
    "pivot = 0",
    "goto L2",
    "t2 = low",
    "t3 = arr [t2]",
    "pivot = t3",
    "i = low",
    "t4 = low + 1",
    "j = t4",
    "t5 = j < high",
    "t6 = not j",
    "if t6 goto L4",
    "t7 = j",
    "t8 = arr [t7]",
    "t9 = t8 < pivot",
    "if t9 goto L5",
    "t: = i + 1",
    "i = t:",
    "t; = i",
    "t< = arr [t;]",
    "t1 = t<",
    "t= = j",
    "t> = arr [t=]",
    "t2 = t>",
    "t< = t2",
    "t= = t1",
    "j = j + 1",
    "goto L3",
    "L5 :",
    "t? = i",
    "t@ = arr [t?]",
    "t1 = t@",
    "tA = low",
    "tB = arr [tA]",
    "t2 = tB",
    "t@ = t2",
    "tA = t1",
    "tC = i + 1",
    "i = tC",
    "L1 :"
]

dag = generate_dag(tac)
basic_blocks = identify_basic_blocks(tac)
cfg = construct_cfg(basic_blocks)

print("DAG:")
print_dag(dag)
print("\nCFG:")
print_cfg(cfg)
