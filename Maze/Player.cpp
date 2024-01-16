#include "pch.h"
#include "Player.h"
#include "Board.h"
#include <stack>

void Player::Init(Board* board)
{
	_pos = board->GetEndterPos();
	_board = board;

	//RightHand();
	Bfs();

}

void Player::Update(uint64 deltaTick)
{
	if (_pathIndex >= _path.size())
		return;

	_sumTick += deltaTick;
	if (_sumTick >= MOVE_TICK)
	{
		_sumTick = 0;

		_pos = _path[_pathIndex];
		_pathIndex++;
	}

}

bool Player::CanGo(Pos pos)
{
	TileType tileType = _board->GetTileType(pos);

	return tileType == TileType::EMPTY;
}

void Player::RightHand()
{
	Pos pos = _pos;

	_path.clear();
	_path.push_back(pos);

	// 목적지 도착하기 전에는 계속 실행
	Pos dest = _board->GetExitPos();

	Pos front[4] =
	{
		Pos {-1,0},
		Pos {0,-1},
		Pos {1,0},
		Pos {0,1},
	};

	while (pos != dest)
	{

		int32 newDir = (_dir - 1 + DIR_COUNT) % DIR_COUNT;
		if (CanGo(pos + front[newDir]))
		{
			_dir = newDir;

			pos += front[_dir];

			_path.push_back(pos);
		}
		else if (CanGo(pos + front[_dir]))
		{
			pos += front[_dir];
			_path.push_back(pos);
		}
		else
		{
			_dir = (_dir + 1) % DIR_COUNT;
		}

	}

	stack<Pos> s;

	for (int i = 0; i < _path.size() - 1; i++)
	{
		if (s.empty() == false && s.top() == _path[i + 1])
			s.pop();
		else
			s.push(_path[i]);
	}

	if (_path.empty() == false)
		s.push(_path.back());

	vector<Pos> path;
	while (s.empty() == false)
	{
		path.push_back(s.top());
		s.pop();
	}

	std::reverse(path.begin(), path.end());

	_path = path;


}


void Player::Bfs()
{
	Pos pos = _pos;

	// 목적지 도착하기 전에는 계속 실행
	Pos dest = _board->GetExitPos();

	Pos front[4] =
	{
		Pos {-1,0},
		Pos {0,-1},
		Pos {1,0},
		Pos {0,1},
	};

	const int32 size = _board->GetSize();
	vector<vector<bool>> discovered(size, vector<bool>(size, false));

	map<Pos, Pos> parent;

	queue<Pos> q;
	q.push(pos);
	discovered[pos.y][pos.x] = true;
	parent[pos] = pos;

	while (q.empty() == false)
	{
		pos = q.front();
		q.pop();

		//방문
		if (pos == dest)
			break;

		for (int32 dir = 0; dir < 4; dir++)
		{
			Pos nextPos = pos + front[dir];
			//갈 수 있는 지역은 맞는지 확인
			if (CanGo(nextPos) == false)
				continue;

			//이미 발견한 지역인지 확인
			if (discovered[nextPos.y][nextPos.x])
				continue;

			q.push(nextPos);
			discovered[nextPos.y][nextPos.x] = true;
			//부모 설정
			parent[nextPos] = pos;

		}
	}

	//경로 계산

	_path.clear();

	pos = dest;

	while (true)
	{
		_path.push_back(pos);

		if (pos == parent[pos])
			break;

		pos = parent[pos];
	}

	std::reverse(_path.begin(), _path.end());
}
