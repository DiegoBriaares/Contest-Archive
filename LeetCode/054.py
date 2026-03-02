class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        N = len(matrix)
        M = len(matrix[0])

        state = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        curr = 0

        vis = [[0] * M for _ in range(N)]
        tot = N * M
        i, j = 0, 0
        ans = []
        while tot:
            ans.append(matrix[i][j])
            vis[i][j] = True
            for _ in range(4):
                new_i = i + state[curr][0]
                new_j = j + state[curr][1]
                if new_i >= N or new_i < 0 or new_j < 0 or new_j >= M or vis[new_i][new_j]:
                    curr = (curr + 1) % 4
                    continue
                else:
                    i, j = new_i, new_j
                    break
            else:
                break
            tot -= 1

        return ans


        
