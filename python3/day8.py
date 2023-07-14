class Node:
    def __init__(self, val: int = 0, left = None, right = None) -> None:
        self.val = val
        self.left = left
        self.right = right

    def __repr__(self) -> str:
        return f"Node(val={repr(self.val)}, left={repr(self.left)}, right={repr(self.right)})"

def count_unival_subtrees(root: Node) -> int:
    def helper(n: Node) -> tuple[int, int | None]:
        # Returns a tuple (c, v)
        # the number of subtrees of the tree rooted at n
        # v is None or int, which is the unival of the tree rooted at n (if it exists)
        c = 0
        v = n.val
        if n.left:
            cl, vl = helper(n.left)
            c += cl
            if v != vl:
                v = None
        if n.right:
            cr, vr = helper(n.right)
            c += cr
            if v != vr:
                v = None
        if v is not None:
            c += 1
        return (c, v)
    if root is None:
        return 0
    return helper(root)[0]

def main():
    t = Node(0, Node(1), Node(0, Node(1, Node(1), Node(1)), Node(0)))
    print(count_unival_subtrees(t))

if __name__ == "__main__":
    main()
