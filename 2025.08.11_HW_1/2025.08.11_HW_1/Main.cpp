#include "Jobs.h"
#include "Monster.h"

int main()
{
    srand(time(NULL));

    string jobs[] = { "����", "������", "����", "�ü�" };
    int job_choice = 0;
    string nickname;

    Player* player = nullptr;
    Monster* monster = new Monster("������");

    cout << "* �г����� �Է����ּ���: ";
    cin >> nickname;

    cout << "<���� �ý���>" << endl;
    cout << nickname << "��, ȯ���մϴ�!" << endl;
    cout << "* ���Ͻô� ������ �������ּ���." << endl;

    for (int i = 0; i < 4; i++)
        cout << (i + 1) << ". " << jobs[i] << endl;

    cout << "����: ";
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
            cout << "�߸��� �Է��Դϴ�." << endl;
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
