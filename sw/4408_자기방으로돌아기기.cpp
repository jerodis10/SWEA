#include <iostream>
#include <cstring>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> node;

int testcase;
int n, ans;
int from, to;
int sx, sy, ex, ey, turn;

int map[3][200];
int dist[3][200];
bool visited[3][200];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void getPos() {
    // ���� ��� ���ϱ�
    if (from % 2 == 1) sx = 0;
    else sx = 2;
    sy = (from + 1) / 2 - 1;

    // ���� ��� ���ϱ�
    if (to % 2 == 1) ex = 0;
    else ex = 2;
    ey = (to + 1) / 2 - 1;

    // �̵� ���� ���ϱ�
    if (from < to) turn = 1;
    else turn = 0;
}

void bfs() {
    queue<node> q;
    q.push(node(sx, sy));
    visited[sx][sy] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // �濡 ���������� Ž�� ����
        if (map[x][y] == to) {
            return;
        }

        for (int i = 0; i < 4; i++) {
            // ��������� �ƴѰ�� ����
            if (turn == i) continue;

            int nx = x + dx[i];
            int ny = y + dy[i];

            // �� ���� ����ų�, �������� �������� �ƴ� �ٸ� ���� �湮�� ��� ����
            if (nx < 0 || ny < 0 || nx >= 200 || ny >= 200) continue;
            if (nx != 1 && map[nx][ny] != to) continue;

            // �������� ������ ���� ��� ����
            if (turn == 0 && ny < ey) continue;
            if (turn == 1 && ny > ey) continue;

            if (!visited[nx][ny]) {
                q.push(node(nx, ny));
                visited[nx][ny] = true;
                dist[nx][ny] += 1;
            }
        }
    }
}

int main(int argc, const char* argv[]) {
    // cin,cout �ӵ����
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        cin >> n;

        // ���ȣ ����
        int nn = 1;
        for (int j = 0; j < 200; j++) {
            for (int i = 0; i < 3; i++) {
                if (i == 1) {
                    map[i][j] = 0;
                }
                else {
                    map[i][j] = nn;
                    nn++;
                }

                dist[i][j] = 0;
            }
        }

        // �Է�
        for (int i = 0; i < n; i++) {
            cin >> from >> to;

            memset(visited, false, sizeof(visited));
            getPos();
            bfs();
        }

        ans = 0;
        for (int j = 0; j < 200; j++) {
            ans = max(ans, dist[1][j]);
        }

        cout << "#" << t << " " << ans << "\n";
    }

    return 0;
}