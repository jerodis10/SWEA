#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct pos {
    int x, y;
};

struct robot {
    pos a, b;
    int flt;
    int cnt;
};

int di[] = { -1,0,1,0 };
int dj[] = { 0,1,0,-1 };

int up[4][2] = {
    {0,0},{0,1},{-1,0},{-1,1}
};
int down[4][2] = {
    {0,0},{0,1},{1,0},{1,1}
};
int Left[4][2] = {
    {0,0},{0,-1},{1,0},{1,-1}
};
int Right[4][2] = {
    {0,0},{0,1},{1,0},{1,1}
};

int N;
int map[100][100];
bool visited[100][100][2];

bool inner(pos a, pos b) {
    if (a.x < 0 || b.x < 0 || a.x >= N || b.x >= N || a.y < 0 || b.y < 0 || a.y >= N || b.y >= N) {
        return false;
    }
    return true;
}

int bfs(robot str) {
    queue<robot> q;
    q.push(str);
    visited[str.a.x][str.a.y][str.flt] = true;

    while (!q.empty()) {
        robot cur = q.front();
        q.pop();

        if ((cur.a.x == N - 1 && cur.a.y == N - 1) || (cur.b.x == N - 1 && cur.b.y == N - 1)) {
            return cur.cnt;
        }

        //4����
        for (int i = 0; i < 4; i++) {
            robot nxt = cur;

            nxt.a.x += di[i];
            nxt.a.y += dj[i];
            nxt.b.x += di[i];
            nxt.b.y += dj[i];

            if (!inner(nxt.a, nxt.b)) {
                continue;
            }

            if (map[nxt.a.x][nxt.a.y] == 0 && map[nxt.b.x][nxt.b.y] == 0 && !visited[nxt.a.x][nxt.a.y][nxt.flt]) {
                nxt.cnt++;
                q.push(nxt);
                visited[nxt.a.x][nxt.a.y][nxt.flt] = true;
            }
        }

        //a,b������ ȸ��
        //���ι����� ���
        if (cur.flt == 0) {
            //�������� ȸ��
            bool isAble = true;
            for (int i = 0; i < 4; i++) {
                int ni = cur.a.x + up[i][0];
                int nj = cur.a.y + up[i][1];

                if (ni < 0 || nj < 0 || ni >= N || nj >= N) {
                    isAble = false;
                }
                if (map[ni][nj] != 0) {
                    isAble = false;
                }
            }

            //�������� ȸ���� �����ϴٸ�, a�� b���� �������� ��� ���� ȸ�� ����
            if (isAble) {
                //a�� �������� ���� ȸ��
                robot nxt = cur;
                nxt.flt = 1;
                nxt.a.x += -1;
                nxt.b.y += -1;
                nxt.cnt++;

                if (!visited[nxt.a.x][nxt.a.y][nxt.flt]) {
                    q.push(nxt);
                    visited[nxt.a.x][nxt.a.y][nxt.flt] = true;
                }

                //b�� �������� ���� ȸ��
                nxt = cur;
                nxt.flt = 1;
                nxt.a.x += -1;
                nxt.a.y += 1;
                nxt.cnt++;

                if (!visited[nxt.a.x][nxt.a.y][nxt.flt]) {
                    q.push(nxt);
                    visited[nxt.a.x][nxt.a.y][nxt.flt] = true;
                }
            }

            //�Ʒ������� ȸ��
            isAble = true;
            for (int i = 0; i < 4; i++) {
                int ni = cur.a.x + down[i][0];
                int nj = cur.a.y + down[i][1];

                if (ni < 0 || nj < 0 || ni >= N || nj >= N) {
                    isAble = false;
                }
                if (map[ni][nj] != 0) {
                    isAble = false;
                }
            }

            if (isAble) {
                robot nxt = cur;
                nxt.flt = 1;
                nxt.b.x += 1;
                nxt.b.y += -1;
                nxt.cnt++;

                if (!visited[nxt.a.x][nxt.a.y][nxt.flt]) {
                    q.push(nxt);
                    visited[nxt.a.x][nxt.a.y][nxt.flt] = true;
                }

                nxt = cur;
                nxt.flt = 1;
                nxt.a.y += 1;
                nxt.b.x += 1;
                nxt.cnt++;

                if (!visited[nxt.a.x][nxt.a.y][nxt.flt]) {
                    q.push(nxt);
                    visited[nxt.a.x][nxt.a.y][nxt.flt] = true;
                }
            }
        }
        else {
            //�������� ȸ��
            bool isAble = true;
            for (int i = 0; i < 4; i++) {
                int ni = cur.a.x + Left[i][0];
                int nj = cur.a.y + Left[i][1];

                if (ni < 0 || nj < 0 || ni >= N || nj >= N) {
                    isAble = false;
                }
                if (map[ni][nj] != 0) {
                    isAble = false;
                }
            }

            if (isAble) {
                robot nxt = cur;
                nxt.flt = 0;
                nxt.a.y += -1;
                nxt.b.x += -1;
                nxt.cnt++;

                if (!visited[nxt.a.x][nxt.a.y][nxt.flt]) {
                    q.push(nxt);
                    visited[nxt.a.x][nxt.a.y][nxt.flt] = true;
                }

                nxt = cur;
                nxt.flt = 0;
                nxt.a.x += 1;
                nxt.a.y += -1;
                nxt.cnt++;

                if (!visited[nxt.a.x][nxt.a.y][nxt.flt]) {
                    q.push(nxt);
                    visited[nxt.a.x][nxt.a.y][nxt.flt] = true;
                }
            }

            //���������� ȸ��
            isAble = true;
            for (int i = 0; i < 4; i++) {
                int ni = cur.a.x + Right[i][0];
                int nj = cur.a.y + Right[i][1];

                if (ni < 0 || nj < 0 || ni >= N || nj >= N) {
                    isAble = false;
                }
                if (map[ni][nj] != 0) {
                    isAble = false;
                }
            }

            if (isAble) {
                robot nxt = cur;
                nxt.flt = 0;
                nxt.b.x += -1;
                nxt.b.y += 1;
                nxt.cnt++;

                if (!visited[nxt.a.x][nxt.a.y][nxt.flt]) {
                    q.push(nxt);
                    visited[nxt.a.x][nxt.a.y][nxt.flt] = true;
                }

                nxt = cur;
                nxt.flt = 0;
                nxt.a.x += 1;
                nxt.b.y += 1;
                nxt.cnt++;

                if (!visited[nxt.a.x][nxt.a.y][nxt.flt]) {
                    q.push(nxt);
                    visited[nxt.a.x][nxt.a.y][nxt.flt] = true;
                }
            }
        }

    }
}

int solution(vector<vector<int>> board) {

    int answer = 0;

    N = board.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[i][j] = board[i][j];
        }
    }

    robot str = { {0,0},{0,1},0,0 };

    answer = bfs(str);

    return answer;
}
