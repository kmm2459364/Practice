//======================================
//      ���[�e�B���e�B
//======================================
using System.Text; // StringBuilder

namespace GP2
{
    static class Utility
    {
        public const string EscBLACK = "\x1b[30m";
        public const string EscRED = "\x1b[31m";
        public const string EscGREEN = "\x1b[32m";
        public const string EscYELLOW = "\x1b[33m";
        public const string EscBLUE = "\x1b[34m";
        public const string EscMAZENTA = "\x1b[35m";
        public const string EscCYAN = "\x1b[36m";
        public const string EscWHITE = "\x1b[37m";
        public const string EscDEFAULT = "\x1b[39m";

        public const string EscBgBLACK = "\x1b[40m";
        public const string EscBgRED = "\x1b[41m";
        public const string EscBgGREEN = "\x1b[42m";
        public const string EscBgYELLOW = "\x1b[43m";
        public const string EscBgBLUE = "\x1b[44m";
        public const string EscBgMAZENTA = "\x1b[45m";
        public const string EscBgCYAN = "\x1b[46m";
        public const string EscBgWHITE = "\x1b[47m";
        public const string EscBgDEFAULT = "\x1b[49m";

        private static Random s_rand = new Random();
        // ����������
        public static void InitRand()
        {
            //s_rand = new Random();
        }
        // �����擾
        public static int GetRand(int max)
        {
            return s_rand.Next(max);
        }
        // �L�[���͑҂�
        public static void WaitKey()
        {
            Console.ReadKey(true);
        }
        // �L�[�擾
        //  ConsoleKey.UpArrow    �J�[�\����
        //  ConsoleKey.DownArrow  �J�[�\����
        //  ConsoleKey.LeftArrow  �J�[�\����
        //  ConsoleKey.RightArrow �J�[�\���E
        //  ConsoleKey.Return     ���^�[���L�[
        //  ConsoleKey.Escape     ESC�L�[
        //  ConsoleKey.Spacebar   �X�y�[�X�L�[
        public static ConsoleKey GetKey()
        {
            ConsoleKeyInfo info = Console.ReadKey(true);
            return info.Key;
        }
        // �L�[�������ꂽ��?
        public static bool KeyAvailable()
        {
            return Console.KeyAvailable;
        }

        static StringBuilder s_console = new StringBuilder();
        //--------------------------------------
        //      �R���\�[���o��
        //--------------------------------------
        // �g���� : StringBuilder�ɂ��ߍ���� PrintOut()�Ŏ��ۂ̕`����s��
        //    Utility.ClearScreen();
        //    Utilitu.Printf(....);
        //    Utility.Putchar(.);
        //    ....
        //    Utility.PrintOut();
        //--------------------------------------
        // ��ʃN���A
        public static void ClearScreen()
        {
            s_console.Clear();
        }
        // printf()�֐�
        public static void Printf(string fmt, params Object[] list)
        {
            s_console.AppendFormat(fmt, list);
        }
        // putchar()�֐�
        public static void Putchar(Char c)
        {
            s_console.Append(c);
        }
        // �v�����g�o��
        public static void PrintOut()
        {
            Console.Clear();
            Console.Write(s_console.ToString());
        }
        // m�b�X���[�v
        public static void Sleep_mSec(int mSec)
        {
            System.Threading.Thread.Sleep(mSec);
        }
    } // class Utility
} // namespace