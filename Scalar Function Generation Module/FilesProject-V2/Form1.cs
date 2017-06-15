using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Xml;

namespace FilesProject_V2
{
    public partial class ScalarFunctionGeneration : Form
    {
        public class Result
        {
            public string result { set; get; }
            public Result()
            {
                result="";
            }
           public  Result(string s)
            {
                result = s;
            }
        }
        public ScalarFunctionGeneration()
        {
            InitializeComponent();
            AssignDataTypes();
        }
        public void AssignDataTypes()
        {
            if (!File.Exists("function datatypes.xml"))
            {
                XmlWriter Writer = XmlWriter.Create("function datatypes.xml");
                Writer.WriteStartDocument();
                Writer.WriteStartElement("ScalarFunctions");

                Writer.WriteStartElement("Sum");
                Writer.WriteString("int");
                Writer.WriteEndElement();

                Writer.WriteStartElement("Sum");
                Writer.WriteString("long");
                Writer.WriteEndElement();

                Writer.WriteStartElement("Sum");
                Writer.WriteString("float");
                Writer.WriteEndElement();

                Writer.WriteStartElement("Sum");
                Writer.WriteString("double");
                Writer.WriteEndElement();

                Writer.WriteStartElement("Average");
                Writer.WriteString("int");
                Writer.WriteEndElement();

                Writer.WriteStartElement("Average");
                Writer.WriteString("long");
                Writer.WriteEndElement();

                Writer.WriteStartElement("Average");
                Writer.WriteString("float");
                Writer.WriteEndElement();

                Writer.WriteStartElement("Average");
                Writer.WriteString("double");
                Writer.WriteEndElement();

                Writer.WriteStartElement("Max");
                Writer.WriteString("int");
                Writer.WriteEndElement();

                Writer.WriteStartElement("Max");
                Writer.WriteString("long");
                Writer.WriteEndElement();

                Writer.WriteStartElement("Max");
                Writer.WriteString("float");
                Writer.WriteEndElement();

                Writer.WriteStartElement("Max");
                Writer.WriteString("double");
                Writer.WriteEndElement();

                Writer.WriteStartElement("Min");
                Writer.WriteString("int");
                Writer.WriteEndElement();

                Writer.WriteStartElement("Min");
                Writer.WriteString("long");
                Writer.WriteEndElement();

                Writer.WriteStartElement("Min");
                Writer.WriteString("float");
                Writer.WriteEndElement();

                Writer.WriteStartElement("Min");
                Writer.WriteString("double");
                Writer.WriteEndElement();

                Writer.WriteStartElement("StringConcatenation");
                Writer.WriteString("string");
                Writer.WriteEndElement();

                Writer.WriteStartElement("CountColumns");
                Writer.WriteString("string");
                Writer.WriteEndElement();

                Writer.WriteStartElement("CountColumns");
                Writer.WriteString("int");
                Writer.WriteEndElement();

                Writer.WriteStartElement("CountColumns");
                Writer.WriteString("long");
                Writer.WriteEndElement();

                Writer.WriteStartElement("CountColumns");
                Writer.WriteString("float");
                Writer.WriteEndElement();

                Writer.WriteStartElement("CountColumns");
                Writer.WriteString("double");
                Writer.WriteEndElement();

                Writer.WriteStartElement("Count");
                Writer.WriteString("string");
                Writer.WriteEndElement();

                Writer.WriteStartElement("Count");
                Writer.WriteString("int");
                Writer.WriteEndElement();

                Writer.WriteStartElement("Count");
                Writer.WriteString("long");
                Writer.WriteEndElement();

                Writer.WriteStartElement("Count");
                Writer.WriteString("float");
                Writer.WriteEndElement();

                Writer.WriteStartElement("Count");
                Writer.WriteString("double");
                Writer.WriteEndElement();

                Writer.WriteStartElement("FirstOf");
                Writer.WriteString("string");
                Writer.WriteEndElement();

                Writer.WriteStartElement("FirstOf");
                Writer.WriteString("int");
                Writer.WriteEndElement();

                Writer.WriteStartElement("FirstOf");
                Writer.WriteString("long");
                Writer.WriteEndElement();

                Writer.WriteStartElement("FirstOf");
                Writer.WriteString("float");
                Writer.WriteEndElement();

                Writer.WriteStartElement("FirstOf");
                Writer.WriteString("double");
                Writer.WriteEndElement();

                Writer.WriteStartElement("LastOf");
                Writer.WriteString("string");
                Writer.WriteEndElement();

                Writer.WriteStartElement("LastOf");
                Writer.WriteString("int");
                Writer.WriteEndElement();

                Writer.WriteStartElement("LastOf");
                Writer.WriteString("long");
                Writer.WriteEndElement();

                Writer.WriteStartElement("LastOf");
                Writer.WriteString("float");
                Writer.WriteEndElement();

                Writer.WriteStartElement("LastOf");
                Writer.WriteString("double");
                Writer.WriteEndElement();

                Writer.WriteStartElement("Search");
                Writer.WriteString("string");
                Writer.WriteEndElement();

                Writer.WriteStartElement("Search");
                Writer.WriteString("int");
                Writer.WriteEndElement();

                Writer.WriteStartElement("Search");
                Writer.WriteString("long");
                Writer.WriteEndElement();

                Writer.WriteStartElement("Search");
                Writer.WriteString("float");
                Writer.WriteEndElement();

                Writer.WriteStartElement("Search");
                Writer.WriteString("double");
                Writer.WriteEndElement();

                Writer.WriteEndElement();
                Writer.WriteEndDocument();
                Writer.Close();
            }

        }
        void GetColumns(string TableName)
        {
            XmlDocument Document = new XmlDocument();
            Document.Load("Sample Test.xml");
            XmlNodeList List = Document.GetElementsByTagName(TableName);
            XmlNodeList Child = List[0].ChildNodes;
            ChosenCol1.Items.Clear();
            ChosenCol2.Items.Clear();
            for (int i = 0; i < Child.Count; i++)
            {
                ChosenCol1.Items.Add(Child[i].Name);
                ChosenCol2.Items.Add(Child[i].Name);
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
        private bool IsValid(string Function, string Type)
        {
            XmlDocument doc = new XmlDocument();
            doc.Load("function datatypes.xml");
            XmlNodeList List = doc.GetElementsByTagName(Function);
            for (int i = 0; i < List.Count; i++)
            {
                if (List[i].InnerText == Type) { return true; }
            }
            return false;
        }
        public string Sum(string ColumnName)
        {
            double sum = 0;

            XmlDocument doc = new XmlDocument();
            doc.Load("Sample Test.xml");
            XmlNodeList List = doc.GetElementsByTagName(ColumnName);
            if (List.Count != 0)
            {
                if (!IsValid("Sum", List[0].Attributes["datatype"].Value))
                {
                    return "Sum function doesn't work with the column datatype";
                }
            }
            for (int i = 0; i < List.Count; i++)
            {
                sum += List[i].InnerText.To<double>();
            }
            return sum.ToString();
        }
        public string Average(string ColumnName)
        {
            if (Sum(ColumnName) != "Sum function doesn't work with the column datatype")
            {
                double sum = Sum(ColumnName).To<double>();
                int n = CountColumns(ColumnName).To<int>();
                sum = sum / n;
                return sum.ToString();
            }
            else
            {
                return "Average function doesn't work with the column datatype";
            }
        }
        public string Max(string ColumnName)
        {
            XmlDocument Document = new XmlDocument();
            Document.Load("Sample Test.xml");
            XmlNodeList List = Document.GetElementsByTagName(ColumnName);
            if (List.Count != 0)
            {
                if (!IsValid("Max", List[0].Attributes["datatype"].Value))
                {
                    return "Max function doesn't work with the column datatype";
                }
            }
            List<double> res = new List<double>();
            for (int i = 0; i < List.Count; i++)
            {
                res.Add(double.Parse(List[i].InnerText));
            }
            res.Sort();
            return res[res.Count - 1].ToString();
        }
        public string Min(string ColumnName)
        {
            XmlDocument Document = new XmlDocument();
            Document.Load("Sample Test.xml");
            XmlNodeList List = Document.GetElementsByTagName(ColumnName);
            List<double> res = new List<double>();
            if (List.Count != 0)
            {
                if (!IsValid("Min", List[0].Attributes["datatype"].Value))
                {
                    return "Min function doesn't work with the column datatype";
                }
            }
            for (int i = 0; i < List.Count; i++)
            {
                res.Add(double.Parse(List[i].InnerText));
            }
            res.Sort();
            return res[0].ToString();
        }
        private string StringConcatenation(string Column1, string Column2)
        {
            XmlDocument Document = new XmlDocument();
            Document.Load("Sample Test.xml");
            XmlNodeList List1 = Document.GetElementsByTagName(Column1);
            XmlNodeList List2 = Document.GetElementsByTagName(Column2);
            /*if (List1.Count != 0)
            {
                if (!IsValid("StringConcatenation", List1[0].Attributes["datatype"].Value))
                {
                    return "StringConcatenation function doesn't work with the first column datatype";
                }
            }
            if (List2.Count != 0)
            {
                if (!IsValid("StringConcatenation", List2[0].Attributes["datatype"].Value))
                {
                    return "StringConcatenation function doesn't work with the second column datatype";
                }
            }*/
            List<Result> res = new List<Result>();
            int i = 0;
            for (; i < Math.Min(List1.Count,List2.Count); i++)
            {
                string S = List1[i].InnerText +" "+ List2[i].InnerText;
                Result Current = new Result(S);
                res.Add(Current);
            }
            for (; i < List1.Count; i++)
            {
                string S = List1[i].InnerText;
                Result Current = new Result(S);
                res.Add(Current);
            }
            for (; i < List2.Count; i++)
            {
                string S = List2[i].InnerText;
                Result Current = new Result(S);
                res.Add(Current);
            }
            StringConc.DataSource = res;
            return "Done";
        }
        public string CountColumns(string ColumnName)
        {
            int Counter = 0;
            XmlDocument Document = new XmlDocument();
            Document.Load("Sample Test.xml");
            XmlNodeList List = Document.GetElementsByTagName(ColumnName);
            if (List.Count != 0)
            {
                if (!IsValid("CountColumns", List[0].Attributes["datatype"].Value))
                {
                    return "Length function doesn't work with the column datatype";
                }
            }
            for (int i = 0; i < List.Count; i++)
            {
                if (List[i].InnerText != null)
                    Counter++;
            }
            return Counter.ToString();
        }
        public string Count(string ColumnName, string SearchAttribute)
        {
            int Counter = 0;
            XmlDocument Document = new XmlDocument();
            Document.Load("Sample Test.xml");
            XmlNodeList List = Document.GetElementsByTagName(ColumnName);
            if (List.Count != 0)
            {
                if (!IsValid("Count", List[0].Attributes["datatype"].Value))
                {
                    return "Count function doesn't work with the column datatype";
                }
            }
            for (int i = 0; i < List.Count; i++)
            {
                if (List[i].InnerText == SearchAttribute)
                    Counter++;
            }
            return Counter.ToString();
        }
        public string LastOf(string ColumnName)
        {
            XmlDocument Document = new XmlDocument();
            Document.Load("Sample Test.xml");
            XmlNodeList List = Document.GetElementsByTagName(ColumnName);
            if (List.Count != 0)
            {
                if (!IsValid("LastOf", List[0].Attributes["datatype"].Value))
                {
                    return "LastOf function doesn't work with the column datatype";
                }
            }
            List<string> res = new List<string>();
            for (int i = 0; i < List.Count; i++)
            {
                res.Add(List[i].InnerText);
            }
            return res[res.Count - 1];
        }
        public string FirstOf(string ColumnName)
        {
            XmlDocument Document = new XmlDocument();
            Document.Load("Sample Test.xml");
            XmlNodeList List = Document.GetElementsByTagName(ColumnName);
            if (List.Count != 0)
            {
                if (!IsValid("FirstOf", List[0].Attributes["datatype"].Value))
                {
                    return "FirstOf function doesn't work with the column datatype";
                }
            }
            List<string> res = new List<string>();
            for (int i = 0; i < List.Count; i++)
            {
                res.Add(List[i].InnerText);
            }
            return res[0];
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            AssignDataTypes();
            SearchAtt.Hide();
            SearchAttTextBox.Hide();
            StringConc.Hide();
            label1.Hide();
            ChosenCol2.Hide();
            GetTables();
        }
        private void FunctionsList_SelectedIndexChanged(object sender, EventArgs e)
        {
            SearchAtt.Hide();
            SearchAttTextBox.Hide();
            label1.Hide();
            ChosenCol2.Hide();
            StringConc.Hide();
            if (FunctionsList.SelectedItem.ToString() == "Count")
            {
                SearchAtt.Text = "Item To Be Counted";
                SearchAtt.Show();
                SearchAttTextBox.Show();
            }
            if (FunctionsList.SelectedItem.ToString() == "StringConcatenation")
            {
                label1.Show();
                ChosenCol2.Show();
            }
        }
        private void Execute_Click(object sender, EventArgs e)
        {
            if (FunctionsList.SelectedItem.ToString() == "Sum")
            {
                MessageBox.Show(Sum(ChosenCol1.Text).ToString());
            }
            else if (FunctionsList.SelectedItem.ToString() == "Average")
            {
                MessageBox.Show(Average(ChosenCol1.Text).ToString());
            }
            else if (FunctionsList.SelectedItem.ToString() == "Max")
            {
                MessageBox.Show(Max(ChosenCol1.Text));
            }
            else if (FunctionsList.SelectedItem.ToString() == "Min")
            {
                MessageBox.Show(Min(ChosenCol1.Text));
            }
            else if (FunctionsList.SelectedItem.ToString() == "StringConcatenation")
            {
                StringConc.Show();
                MessageBox.Show(StringConcatenation(ChosenCol1.SelectedItem.ToString(), ChosenCol2.SelectedItem.ToString()));
            }
            else if (FunctionsList.SelectedItem.ToString() == "Length")
            {
                MessageBox.Show(CountColumns(ChosenCol1.Text).ToString());
            }
            else if (FunctionsList.SelectedItem.ToString() == "Count")
            {
                MessageBox.Show(Count(ChosenCol1.Text, SearchAttTextBox.Text).ToString());
            }
            else if (FunctionsList.SelectedItem.ToString() == "LastOf")
            {
                MessageBox.Show(LastOf(ChosenCol1.Text));
            }
            else if (FunctionsList.SelectedItem.ToString() == "FirstOf")
            {
                MessageBox.Show(FirstOf(ChosenCol1.Text));
            }
        }
        private void newform_Click(object sender, EventArgs e)
        {
            this.Hide();
            Bonus b = new Bonus();
            b.ShowDialog();
            this.Close();
        }
        private void ChoosenTables_SelectedIndexChanged(object sender, EventArgs e)
        {
            GetColumns(ChosenTables.Text);
        }
    }
}

