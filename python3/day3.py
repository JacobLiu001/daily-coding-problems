# Given the root to a binary tree, implement:
# - serialize(root), which serializes the tree into a string, 
# - and deserialize(s), which deserializes the string back into the tree.

# For example, given the following Node class

# class Node:
#     def __init__(self, val, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# The following test should pass:

# node = Node('root', Node('left', Node('left.left')), Node('right'))
# assert deserialize(serialize(node)).left.left.val == 'left.left'

# ===================================================
# We use the convention that `eval(repr(x)) == x`.

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left: Node | None = left
        self.right: Node | None = right
    
    def __repr__(self) -> str:
        return f"Node({repr(self.val)}, {repr(self.left)}, {repr(self.right)})"

def serialize(root: Node) -> str:
    return repr(root)

def deserialize(s: str) -> Node:
    # Since we don't know the type of the payload
    # We sort of don't have a better solution
    # Maybe pickling might be ever-so-slightly safer.
    return eval(s)

def main():
    node = Node('root', Node('left', Node('left.left')), Node('right'))
    assert deserialize(serialize(node)).left.left.val == 'left.left'

if __name__ == "__main__":
    main()