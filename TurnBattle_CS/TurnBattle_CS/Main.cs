//======================================
//      �^�[�����o�g�� ���C��
//======================================
using System;    // ConsoleKey
using Utility = GP2.Utility;

namespace TurnBattle_CS
{
    class TurnBattleMain
    {
        static int Main()
        {
            Utility.InitRand();
            Audio.Setup();

            ConsoleKey c;
            do
            {
                Game();
                Utility.Printf("������x(y/n)?");
                Utility.PrintOut();
                while (true)
                {
                    c = Utility.GetKey();
                    if (c == ConsoleKey.Y || c == ConsoleKey.N)
                    {
                        break;
                    }
                }
            } while (c == ConsoleKey.Y);

            Audio.Remove();
            return 0;
        }

        static void Game()
        {
            Character player = new Character(
                100,        // HP
                15,         // MP
                30,         // �U����
                "�䂤����", // ���O
                ""          // �A�X�L�[�A�[�g
                );
            Character boss = new Character(
                255,        // HP
                 0,         // MP
                 50,        // �U����
                 "�܂���",  // ���O
                "�@�@�`���`\n" +   // �A�X�L�[�A�[�g
                "�Ձi���M���j��"
                );
            Character zako = new Character(
                3,         // HP
                0,         // MP
                2,         // �U����
                "�X���C��",// ���O
                "�^�E�D�E�_\n" + // �A�X�L�[�A�[�g
                "�`�`�`�`�`"
                );
            TurnBattle btl = new TurnBattle(player, boss);

            btl.Start();
            btl.Intro();
            bool isEnd = false;
            Command cmd;
            while (true)
            {
                cmd = CommandUI.GetPlayerCommand(btl);
                isEnd = btl.ExecPlayerTurn(cmd);
                if (isEnd)
                {
                    break;
                }
                cmd = CommandAI.GetEnemyCommand();
                isEnd = btl.ExecEnemyTurn(cmd);
                if (isEnd)
                {
                    break;
                }
                btl.NextTurn();
            }
        }
    } // class
} // namespace 