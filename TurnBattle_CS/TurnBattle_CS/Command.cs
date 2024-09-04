//======================================
//      �R�}���h
//======================================using System;
using System;     // ConsoleKey
using Utility = GP2.Utility;

namespace TurnBattle_CS
{
    enum Command
    {
        Fight,  // ��������
        Spell,  // �������
        Escape, // �ɂ���
        Max,
    }

    static class CommandUI
    {
        static string[] commandName = new string[]
        {
            "��������",
            "�������",
            "�ɂ���",
        };
        // �v���[���R�}���h�擾
        public static Command GetPlayerCommand(TurnBattle btl)
        {
            const int cmdMax = (int)Command.Max;

            int cmd = 0;
            while (true)
            {
                btl.DrawBattleScreen();
                for (int i = 0; i < cmdMax; i++)
                {
                    string cur = (i == cmd) ? "��" : "�@";
                    Utility.Printf("{0}{1}\n", cur, commandName[i]);
                }
                Utility.PrintOut();
                switch (Utility.GetKey())
                {
                    case ConsoleKey.UpArrow:
                        cmd--;
                        if (cmd < 0)
                        {
                            cmd = cmdMax - 1;
                        }
                        Audio.PlaySe(SeId.Cursor);
                        break;
                    case ConsoleKey.DownArrow:
                        cmd++;
                        if (cmd >= cmdMax)
                        {
                            cmd = 0;
                        }
                        Audio.PlaySe(SeId.Cursor);
                        break;
                    case ConsoleKey.Enter:
                        Audio.PlaySe(SeId.Decide);
                        return (Command)cmd;
                }
            }
        }
    } // class CommandUI
    static class CommandAI
    {
        // �G�̃R�}���h�擾
        public static Command GetEnemyCommand()
        {
            return Command.Fight;
        }
    } // class CommandAI
} // namespace