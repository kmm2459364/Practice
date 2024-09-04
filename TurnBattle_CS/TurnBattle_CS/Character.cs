//======================================
//      �L�����N�^�[
//======================================
using System;
using Utility = GP2.Utility;

namespace TurnBattle_CS
{
    class Character
    {
        const int SPELL_COST = 3;
        private int m_hp;
        private int m_maxHp;
        private int m_mp;
        private int m_maxMp;
        private int m_attack;
        private string m_name;
        private string m_aa;
        private bool m_isEscape;
        private bool m_isEraseAa;

        // �R���X�g���N�^
        public Character(int hp, int mp, int attack, string name, string aa)
        {
            m_maxHp = hp;
            m_maxMp = mp;
            m_attack = attack;
            m_name = name;
            m_aa = aa;
        }
        // �퓬�J�n
        public void Start()
        {
            m_hp = m_maxHp;
            m_mp = m_maxMp;
            m_isEscape = false;
            m_isEraseAa = false;
        }
        // ���S��?
        public bool IsDead()
        {
            return m_hp == 0;
        }
        // �_���[�W�󂯂�
        public void Damage(int dmg)
        {
            m_hp -= dmg;
            if (m_hp < 0)
            {
                m_hp = 0;
            }
        }
        // �񕜂���
        public void Recover()
        {
            m_hp = m_maxHp;
        }
        // �����ł��邩?
        public bool CanSpell()
        {
            return m_mp >= SPELL_COST;
        }
        // �������g��
        public void UseSpell()
        {
            m_mp -= SPELL_COST;
            if (m_mp < 0)
            {
                m_mp = 0;
            }
        }
        // �v���[���\��
        public void IndicatePlayer()
        {
            Utility.Printf("{0}\n", m_name);
            Utility.Printf("�g�o�F{0,3}�^{1}�@�l�o�F{2,2}�^{3}\n", m_hp, m_maxHp, m_mp, m_maxMp);
        }
        // �G�\��
        public void IndicateEnemy()
        {
            if (m_isEraseAa == false)
            {
                Utility.Printf("{0}", m_aa);
            }
            Utility.Printf("�i�g�o�F{0,3}�^{1}�j\n", m_hp, m_maxHp);
        }
        public int CalcDamage()
        {
            int dmg = Utility.GetRand(m_attack) + 1;
            return dmg;
        }
        // ���O���擾
        public String Name
        {
            get { return m_name; }
        }
        // �ɂ�����?
        public bool IsEscape
        {
            get { return m_isEscape; }
            set { m_isEscape = value; }
        }
        // �A�X�L�[�A�[�g�����ݒ�
        public bool IsEraseAa
        {
            get { return m_isEraseAa; }
            set { m_isEraseAa = value; }
        }
    } // class Character
} // namespace