namespace Learn
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string s1=textBox1.Text;
            MessageBox.Show($"��������ַ���{textBox1.Text.Length}��");
            MessageBox.Show(s1.Contains("gi"));
            MessageBox.Show(s1.ToLower());
        }
    }
}