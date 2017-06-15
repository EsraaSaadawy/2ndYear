namespace FilesProject_V2
{
    partial class Bonus
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.SearchKeyword = new System.Windows.Forms.TextBox();
            this.TableName = new System.Windows.Forms.Label();
            this.ColName = new System.Windows.Forms.Label();
            this.SearchAtt = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.Tamer = new System.Windows.Forms.Button();
            this.ChosenColumn = new System.Windows.Forms.ComboBox();
            this.ChosenTables = new System.Windows.Forms.ComboBox();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(12, 177);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowTemplate.Height = 24;
            this.dataGridView1.Size = new System.Drawing.Size(594, 266);
            this.dataGridView1.TabIndex = 0;
            // 
            // SearchKeyword
            // 
            this.SearchKeyword.Location = new System.Drawing.Point(444, 72);
            this.SearchKeyword.Name = "SearchKeyword";
            this.SearchKeyword.Size = new System.Drawing.Size(107, 22);
            this.SearchKeyword.TabIndex = 2;
            // 
            // TableName
            // 
            this.TableName.AutoSize = true;
            this.TableName.Location = new System.Drawing.Point(26, 25);
            this.TableName.Name = "TableName";
            this.TableName.Size = new System.Drawing.Size(85, 17);
            this.TableName.TabIndex = 4;
            this.TableName.Text = "Table Name";
            // 
            // ColName
            // 
            this.ColName.AutoSize = true;
            this.ColName.Location = new System.Drawing.Point(229, 25);
            this.ColName.Name = "ColName";
            this.ColName.Size = new System.Drawing.Size(73, 17);
            this.ColName.TabIndex = 5;
            this.ColName.Text = "Col. Name";
            // 
            // SearchAtt
            // 
            this.SearchAtt.AutoSize = true;
            this.SearchAtt.Location = new System.Drawing.Point(441, 25);
            this.SearchAtt.Name = "SearchAtt";
            this.SearchAtt.Size = new System.Drawing.Size(110, 17);
            this.SearchAtt.TabIndex = 6;
            this.SearchAtt.Text = "Search Attribute";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(103, 129);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(142, 23);
            this.button1.TabIndex = 7;
            this.button1.Text = "GO ! ";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Tamer
            // 
            this.Tamer.Location = new System.Drawing.Point(326, 129);
            this.Tamer.Name = "Tamer";
            this.Tamer.Size = new System.Drawing.Size(130, 23);
            this.Tamer.TabIndex = 8;
            this.Tamer.Text = "Back";
            this.Tamer.UseVisualStyleBackColor = true;
            this.Tamer.Click += new System.EventHandler(this.Back_Click);
            // 
            // ChosenColumn
            // 
            this.ChosenColumn.FormattingEnabled = true;
            this.ChosenColumn.Location = new System.Drawing.Point(232, 70);
            this.ChosenColumn.Name = "ChosenColumn";
            this.ChosenColumn.Size = new System.Drawing.Size(121, 24);
            this.ChosenColumn.TabIndex = 9;
            // 
            // ChosenTables
            // 
            this.ChosenTables.FormattingEnabled = true;
            this.ChosenTables.Location = new System.Drawing.Point(29, 70);
            this.ChosenTables.Name = "ChosenTables";
            this.ChosenTables.Size = new System.Drawing.Size(131, 24);
            this.ChosenTables.TabIndex = 10;
            this.ChosenTables.SelectedIndexChanged += new System.EventHandler(this.ChosenTables_SelectedIndexChanged);
            // 
            // Bonus
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(618, 455);
            this.Controls.Add(this.ChosenTables);
            this.Controls.Add(this.ChosenColumn);
            this.Controls.Add(this.Tamer);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.SearchAtt);
            this.Controls.Add(this.ColName);
            this.Controls.Add(this.TableName);
            this.Controls.Add(this.SearchKeyword);
            this.Controls.Add(this.dataGridView1);
            this.Name = "Bonus";
            this.Text = "Bonus";
            this.Load += new System.EventHandler(this.Bonus_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.TextBox SearchKeyword;
        private System.Windows.Forms.Label TableName;
        private System.Windows.Forms.Label ColName;
        private System.Windows.Forms.Label SearchAtt;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button Tamer;
        private System.Windows.Forms.ComboBox ChosenColumn;
        private System.Windows.Forms.ComboBox ChosenTables;
    }
}