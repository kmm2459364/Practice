//======================================
//      �^�[�����o�g��
//======================================
using System;
using Utility = GP2.Utility;

namespace TurnBattle_CS
{
    class TurnBattle
    {
        private Character m_player;
        private Character m_enemy;
        private int m_turn;

        // �R���X�g���N�^
        public TurnBattle(Character player, Character enemy)
        {
            m_player = player;
            m_enemy = enemy;
        }
        // �C���g���u�`�����ꂽ�v��\��
        public void Intro()
        {
            DrawBattleScreen();
            Utility.Printf("{0}���@�����ꂽ!\n", m_enemy.Name);
            Utility.PrintOut();
            Utility.WaitKey();
        }
        // �퓬�J�n
        public void Start()
        {
            m_turn = 1;
            m_player.Start();
            m_enemy.Start();
        }
        // ��ʕ\��
        public void DrawBattleScreen()
        {
            Utility.ClearScreen();
            m_player.IndicatePlayer();
            Utility.Putchar('\n');
            m_enemy.IndicateEnemy();
            Utility.Putchar('\n');
        }
        // �v���[���̃^�[�����s
        public bool ExecPlayerTurn(Command cmd)
        {
            execCommand(cmd, m_player, m_enemy);
            if (m_enemy.IsDead())
            {
                m_enemy.IsEraseAa = true;
                DrawBattleScreen();
                Utility.Printf("{0}���@��������!\n", m_enemy.Name);
                Utility.PrintOut();
                Utility.WaitKey();
                return true;
            }
            return m_player.IsEscape;
        }
        // �G�̃^�[�����s
        public bool ExecEnemyTurn(Command cmd)
        {
            execCommand(cmd, m_enemy, m_player);
            if (m_player.IsDead())
            {
                DrawBattleScreen();
                Utility.Printf("���Ȃ��́@���ɂ܂���\n");
                Utility.PrintOut();
                Utility.WaitKey();
                return true;
            }
            return false;
        }
        // �R�}���h���s
        private void execCommand(Command cmd, Character offense, Character defense)
        {
            int dmg = 0;
            switch (cmd)
            {
                case Command.Fight:
                    DrawBattleScreen();
                    Utility.Printf("{0}�́@��������!\n", offense.Name);
                    Utility.PrintOut();
                    Utility.WaitKey();

                    dmg = offense.CalcDamage();
                    defense.Damage(dmg);
                    DrawBattleScreen();
                    Utility.Printf("{0}�Ɂ@{1}�́@�_���[�W!\n", defense.Name, dmg);
                    Utility.PrintOut();
                    Utility.WaitKey();

                    break;
                case Command.Spell:
                    if (offense.CanSpell() == false)
                    {
                        DrawBattleScreen();
                        Utility.Printf("�l�o���@����Ȃ�!\n");
                        Utility.PrintOut();
                        Utility.WaitKey();
                        break;
                    }
                    offense.UseSpell();
                    DrawBattleScreen();
                    Utility.Printf("{0}�́@�q�[�����@�ƂȂ���!\n", offense.Name);
                    Utility.PrintOut();
                    Utility.WaitKey();

                    offense.Recover();
                    DrawBattleScreen();
                    Utility.Printf("{0}�̂������@�����ӂ�����!\n", offense.Name);
                    Utility.PrintOut();
                    Utility.WaitKey();
                    break;

                case Command.Escape:
                    DrawBattleScreen();
                    Utility.Printf("{0}�́@�ɂ�������!\n", offense.Name);
                    Utility.PrintOut();
                    Utility.WaitKey();
                    offense.IsEscape = true;
                    break;
            }
        }
        // ���̃^�[����
        public void NextTurn()
        {
            m_turn++;
        }
    } // class TurnBattle
} // namespace