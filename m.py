import sys

# Increase recursion depth just in case
sys.setrecursionlimit(200000)

def solve():
    # Fast I/O
    input = sys.stdin.read
    data = input().split()
    iterator = iter(data)
    
    try:
        num_test_cases = int(next(iterator))
    except StopIteration:
        return

    results = []

    for _ in range(num_test_cases):
        n = int(next(iterator))
        m = int(next(iterator))
        
        # Read grid (1-based indexing for convenience with padding)
        # We will pad the grid with infinity to avoid boundary checks
        grid = []
        INF = 10**18
        
        # Padding top
        grid.append([INF] * (m + 2))
        
        for _ in range(n):
            row = [INF]
            for _ in range(m):
                row.append(int(next(iterator)))
            row.append(INF)
            grid.append(row)
            
        # Padding bottom
        grid.append([INF] * (m + 2))
        
        q = int(next(iterator))
        
        # Precompute Active status
        # active[r][c] is True if grid[r][c] <= all neighbors
        active = [[False] * (m + 2) for _ in range(n + 2)]

        def update_active_status(r, c):
            if r < 1 or r > n or c < 1 or c > m:
                return
            val = grid[r][c]
            # Check 4 neighbors
            is_act = (val <= grid[r-1][c] and 
                      val <= grid[r+1][c] and 
                      val <= grid[r][c-1] and 
                      val <= grid[r][c+1])
            active[r][c] = is_act

        # Initial active calculation
        for r in range(1, n + 1):
            for c in range(1, m + 1):
                update_active_status(r, c)
                
        # Helper to get contribution of specific elements
        
        def get_node_weight(r, c):
            if r < 1 or r > n or c < 1 or c > m: return 0
            return 1 if active[r][c] else 0
            
        def get_edge_weight_h(r, c):
            # Horizontal edge between (r, c) and (r, c+1)
            if r < 1 or r > n or c < 1 or c >= m: return 0
            if grid[r][c] != grid[r][c+1]: return 0
            if active[r][c] or active[r][c+1]: return -1
            return 0
            
        def get_edge_weight_v(r, c):
            # Vertical edge between (r, c) and (r+1, c)
            if r < 1 or r >= n or c < 1 or c > m: return 0
            if grid[r][c] != grid[r+1][c]: return 0
            if active[r][c] or active[r+1][c]: return -1
            return 0
            
        def get_face_weight(r, c):
            # Face with top-left at (r, c)
            if r < 1 or r >= n or c < 1 or c >= m: return 0
            
            v1 = grid[r][c]
            v2 = grid[r][c+1]
            v3 = grid[r+1][c]
            v4 = grid[r+1][c+1]
            
            # Must be all equal
            if not (v1 == v2 == v3 == v4): return 0
            
            a1 = active[r][c]
            a2 = active[r][c+1]
            a3 = active[r+1][c]
            a4 = active[r+1][c+1]
            
            cnt = a1 + a2 + a3 + a4
            
            if cnt == 4: return 1
            if cnt == 3: return 0
            if cnt == 1: return 1
            if cnt == 0: return 0
            
            # Case 2: Adjacent or Diagonal
            if (a1 and a4) or (a2 and a3): return 2 # Diagonal
            return 1 # Adjacent
        
        current_beauty = 0
        
        # Calculate initial beauty
        for r in range(1, n + 1):
            for c in range(1, m + 1):
                current_beauty += get_node_weight(r, c)
                if c < m: current_beauty += get_edge_weight_h(r, c)
                if r < n: current_beauty += get_edge_weight_v(r, c)
                if r < n and c < m: current_beauty += get_face_weight(r, c)
        
        results.append(str(current_beauty))
        
        # Process Queries
        for _ in range(q):
            qr = int(next(iterator))
            qc = int(next(iterator))
            qx = int(next(iterator))
            
            # Determine affected region
            # We need to re-evaluate active status for (qr, qc) and its neighbors.
            # Then we need to update weights for nodes, edges, faces involving these cells.
            
            # Cells whose active status might change
            cells_to_update = set()
            cells_to_update.add((qr, qc))
            for dr, dc in [(-1,0), (1,0), (0,-1), (0,1)]:
                cells_to_update.add((qr+dr, qc+dc))
            
            # Elements whose weights might change (Nodes, Edges, Faces)
            # We collect the coordinates of the 'anchors' for these elements.
            # Node anchor: (r,c)
            # Edge H anchor: (r,c) (edge to right)
            # Edge V anchor: (r,c) (edge to down)
            # Face anchor: (r,c) (top-left)
            
            calc_nodes = set()
            calc_edges_h = set()
            calc_edges_v = set()
            calc_faces = set()
            
            for r, c in cells_to_update:
                if 1 <= r <= n and 1 <= c <= m:
                    # Node weight depends on this cell
                    calc_nodes.add((r, c))
                    
                    # Edges connected to this cell
                    # Horizontal: (r, c-1)-Right and (r, c)-Right
                    calc_edges_h.add((r, c-1))
                    calc_edges_h.add((r, c))
                    
                    # Vertical: (r-1, c)-Down and (r, c)-Down
                    calc_edges_v.add((r-1, c))
                    calc_edges_v.add((r, c))
                    
                    # Faces containing this cell
                    # (r-1, c-1), (r-1, c), (r, c-1), (r, c)
                    calc_faces.add((r-1, c-1))
                    calc_faces.add((r-1, c))
                    calc_faces.add((r, c-1))
                    calc_faces.add((r, c))
            
            # Subtract old contributions
            for r, c in calc_nodes: current_beauty -= get_node_weight(r, c)
            for r, c in calc_edges_h: current_beauty -= get_edge_weight_h(r, c)
            for r, c in calc_edges_v: current_beauty -= get_edge_weight_v(r, c)
            for r, c in calc_faces: current_beauty -= get_face_weight(r, c)
            
            # Apply Update
            grid[qr][qc] -= qx
            
            # Recompute Active Status
            for r, c in cells_to_update:
                update_active_status(r, c)
            
            # Add new contributions
            for r, c in calc_nodes: current_beauty += get_node_weight(r, c)
            for r, c in calc_edges_h: current_beauty += get_edge_weight_h(r, c)
            for r, c in calc_edges_v: current_beauty += get_edge_weight_v(r, c)
            for r, c in calc_faces: current_beauty += get_face_weight(r, c)
            
            results.append(str(current_beauty))
            
    sys.stdout.write('\n'.join(results) + '\n')

if __name__ == '__main__':
    solve()
