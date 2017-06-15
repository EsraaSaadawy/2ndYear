using System;
using System.Xml;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FilesProject_V2
{
    public partial class Bonus : Form
    {
        public Bonus()
        {
            InitializeComponent();
        }
        void GetColumns(string TableName)
        {
            XmlDocument Document = new XmlDocument();
            Document.Load("Sample Test.xml");
            XmlNodeList List = Document.GetElementsByTagName(TableName);
            XmlNodeList Child = List[0].ChildNodes;
            ChosenColumn.Items.Clear();
            for (int i = 0; i < Child.Count; i++)
            {
                ChosenColumn.Items.Add(Child[i].Name);
            }
        }
        public void GetTables()
        {
            HashSet<string> Check = new HashSet<string>();
            XmlDocument Document = new XmlDocument();
            Document.Load("Sample Test.xml");
            XmlNodeList List = Document.GetElementsByTagName(Document.DocumentElement.Name);
            XmlNodeList Child = List[0].ChildNodes;
            for (int i = 0; i < Child.Count; i++)
            {
                if (!Check.Contains(Child[i].Name))
                {
                    Check.Add(Child[i].Name);
                    ChosenTables.Items.Add(Child[i].Name);
                }
            }
        }
        public void Search(string TableName, string ColumnName, string SearchAttribute)
        {
            DataTable Table = new DataTable();
            XmlDocument Document = new XmlDocument();
            Document.Load("Sample Test.xml");
            XmlNodeList List = Document.GetElementsByTagName(TableName);
            XmlNodeList Children = List[0].ChildNodes;
            for(int i = 0; i < Children.Count; i++)
            {
                DataColumn Column = new DataColumn();
                Column.ColumnName = Children[i].Name;
                Table.Columns.Add(Column);
            }
            for (int i = 0; i < List.Count; i++)
            {
                Children = List[i].ChildNodes;
                for (int j = 0; j < Children.Count; j++)
                {
                    if (Children[j].Name == ColumnName && Children[j].InnerText == SearchAttribute)
                    {
                        DataRow Row = Table.NewRow();
                        for(int k = 0; k < Children.Count; k++)
                        {
                            Row[Children[k].Name] = Children[k].InnerText;
                        }
                        Table.Rows.Add(Row);
                        break;
                    }
                }
            }
            dataGridView1.DataSource = Table;
        }
        private void button1_Click(object sender, EventArgs e)
        {
            Search(ChosenTables.Text, ChosenColumn.Text, SearchKeyword.Text);
        }
        private void Back_Click(object sender, EventArgs e)
        {
            this.Hide();
            ScalarFunctionGeneration f = new ScalarFunctionGeneration();
            f.ShowDialog();
            this.Close();
        }

        private void Bonus_Load(object sender, EventArgs e)
        {
            GetTables();
        }

        private void ChosenTables_SelectedIndexChanged(object sender, EventArgs e)
        {
            GetColumns(ChosenTables.Text);
            
        }
    }
}
