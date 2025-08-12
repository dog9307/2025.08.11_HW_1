#include "Jobs.h"
#include "Monster.h"

int main()
{
    srand(time(NULL));

    string jobs[] = { "전사", "마법사", "도적", "궁수" };
    int job_choice = 0;
    string nickname;

    Player* player = nullptr;
    Monster* monster = new Monster("가고일");

    cout << "* 닉네임을 입력해주세요: ";
    cin >> nickname;

    cout << "<전직 시스템>" << endl;
    cout << nickname << "님, 환영합니다!" << endl;
    cout << "* 원하시는 직업을 선택해주세요." << endl;

    for (int i = 0; i < 4; i++)
        cout << (i + 1) << ". " << jobs[i] << endl;

    cout << "선택: ";
    cin >> job_choice;

    switch (job_choice) {
        case 1:
            player = new Warrior(nickname);
        break;

        case 2:
            player = new Magician(nickname);
        break;

        case 3:
            player = new Thief(nickname);
        break;

        case 4:
            player = new Archer(nickname);
        break;

        default:
            cout << "잘못된 입력입니다." << endl;
        return 1;
    }

    do
    {
        if (player->getSpeed() > monster->getSpeed())
        {
            player->Attack(monster);

            if (monster->getHP() > 0)
                monster->Attack(player);
        }
        else if (player->getSpeed() < monster->getSpeed())
        {
            monster->Attack(player);

            if (player->getHP() > 0)
                player->Attack(monster);
        }
        else
        {
            int random = rand();
            if (random % 2 == 0)
            {
                player->Attack(monster);

                if (monster->getHP() > 0)
                    monster->Attack(player);
            }
            else
            {
                monster->Attack(player);

                if (player->getHP() > 0)
                    player->Attack(monster);
            }
        }

    } while (player->getHP() > 0 && monster->getHP() > 0);

    player->printPlayerStatus();

    delete player;
    delete monster;

	return 0;
}
