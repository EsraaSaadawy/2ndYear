namespace FilesProject_V2
{
    partial class ScalarFunctionGeneration
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
            this.FunctionsList = new System.Windows.Forms.ComboBox();
            this.ChooseFunctionLabel = new System.Windows.Forms.Label();
            this.ColName = new System.Windows.Forms.Label();
            this.SearchAtt = new System.Windows.Forms.Label();
            this.SearchAttTextBox = new System.Windows.Forms.TextBox();
            this.Execute = new System.Windows.Forms.Button();
            this.newform = new System.Windows.Forms.Button();
            this.ChosenCol1 = new System.Windows.Forms.ComboBox();
            this.ColumName = new System.Windows.Forms.Label();
            this.StringConc = new System.Windows.Forms.DataGridView();
            this.label1 = new System.Windows.Forms.Label();
            this.ChosenCol2 = new System.Windows.Forms.ComboBox();
            this.ChosenTables = new System.Windows.Forms.ComboBox();
            ((System.ComponentModel.ISupportInitialize)(this.StringConc)).BeginInit();
            this.SuspendLayout();
            // 
            // FunctionsList
            // 
            this.FunctionsList.FormattingEnabled = true;
            this.FunctionsList.Items.AddRange(new object[] {
            "Sum",
            "Average",
            "Min",
            "Max",
            "StringConcatenation",
            "Length",
            "Count",
            "LastOf",
            "FirstOf"});
            this.FunctionsList.Location = new System.Drawing.Point(262, 54);
            this.FunctionsList.Name = "FunctionsList";
            this.FunctionsList.Size = new System.Drawing.Size(132, 24);
            this.FunctionsList.TabIndex = 0;
            this.FunctionsList.SelectedIndexChanged += new System.EventHandler(this.FunctionsList_SelectedIndexChanged);
            // 
            // ChooseFunctionLabel
            // 
            this.ChooseFunctionLabel.AutoSize = true;
            this.ChooseFunctionLabel.Location = new System.Drawing.Point(66, 61);
            this.ChooseFunctionLabel.Name = "ChooseFunctionLabel";
            this.ChooseFunctionLabel.Size = new System.Drawing.Size(110, 17);
            this.ChooseFunctionLabel.TabIndex = 1;
            this.ChooseFunctionLabel.Text = "Choose function";
            // 
            // ColName
            // 
            this.ColName.AutoSize = true;
            this.ColName.Location = new System.Drawing.Point(66, 116);
            this.ColName.Name = "ColName";
            this.ColName.Size = new System.Drawing.Size(123, 17);
            this.ColName.TabIndex = 2;
            this.ColName.Text = "Enter Table Name";
            // 
            // SearchAtt
            // 
            this.SearchAtt.AutoSize = true;
            this.SearchAtt.Location = new System.Drawing.Point(67, 273);
            this.SearchAtt.Name = "SearchAtt";
            this.SearchAtt.Size = new System.Drawing.Size(125, 17);
            this.SearchAtt.TabIndex = 5;
            this.SearchAtt.Text = "Item to be counted";
            // 
            // SearchAttTextBox
            // 
            this.SearchAttTextBox.Location = new System.Drawing.Point(262, 270);
            this.SearchAttTextBox.Name = "SearchAttTextBox";
            this.SearchAttTextBox.Size = new System.Drawing.Size(132, 22);
            this.SearchAttTextBox.TabIndex = 6;
            // 
            // Execute
            // 
            this.Execute.Location = new System.Drawing.Point(70, 363);
            this.Execute.Name = "Execute";
            this.Execute.Size = new System.Drawing.Size(142, 33);
            this.Execute.TabIndex = 7;
            this.Execute.Text = "Execute";
            this.Execute.UseVisualStyleBackColor = true;
            this.Execute.Click += new System.EventHandler(this.Execute_Click);
            // 
            // newform
            // 
            this.newform.Location = new System.Drawing.Point(262, 363);
            this.newform.Name = "newform";
            this.newform.Size = new System.Drawing.Size(133, 33);
            this.newform.TabIndex = 8;
            this.newform.Text = "Search";
            this.newform.UseVisualStyleBackColor = true;
            this.newform.Click += new System.EventHandler(this.newform_Click);
            // 
            // ChosenCol1
            // 
            this.ChosenCol1.FormattingEnabled = true;
            this.ChosenCol1.Location = new System.Drawing.Point(262, 168);
            this.ChosenCol1.Name = "ChosenCol1";
            this.ChosenCol1.Size = new System.Drawing.Size(132, 24);
            this.ChosenCol1.TabIndex = 9;
            // 
            // ColumName
            // 
            this.ColumName.AutoSize = true;
            this.ColumName.Location = new System.Drawing.Point(66, 168);
            this.ColumName.Name = "ColumName";
            this.ColumName.Size = new System.Drawing.Size(121, 17);
            this.ColumName.TabIndex = 10;
            this.ColumName.Text = "Choose Col.Name";
            // 
            // StringConc
            // 
            this.StringConc.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.StringConc.Location = new System.Drawing.Point(438, 54);
            this.StringConc.Name = "StringConc";
            this.StringConc.RowTemplate.Height = 24;
            this.StringConc.Size = new System.Drawing.Size(246, 342);
            this.StringConc.TabIndex = 11;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(66, 219);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(133, 17);
            this.label1.TabIndex = 13;
            this.label1.Text = "Choose Col.2 Name";
            // 
            // ChosenCol2
            // 
            this.ChosenCol2.FormattingEnabled = true;
            this.ChosenCol2.Location = new System.Drawing.Point(263, 219);
            this.ChosenCol2.Name = "ChosenCol2";
            this.ChosenCol2.Size = new System.Drawing.Size(132, 24);
            this.ChosenCol2.TabIndex = 12;
            // 
            // ChosenTables
            // 
            this.ChosenTables.FormattingEnabled = true;
            this.ChosenTables.Location = new System.Drawing.Point(262, 116);
            this.ChosenTables.Name = "ChosenTables";
            this.ChosenTables.Size = new System.Drawing.Size(131, 24);
            this.ChosenTables.TabIndex = 14;
            this.ChosenTables.SelectedIndexChanged += new System.EventHandler(this.ChoosenTables_SelectedIndexChanged);
            // 
            // ScalarFunctionGeneration
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(812, 459);
            this.Controls.Add(this.ChosenTables);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.ChosenCol2);
            this.Controls.Add(this.StringConc);
            this.Controls.Add(this.ColumName);
            this.Controls.Add(this.ChosenCol1);
            this.Controls.Add(this.newform);
            this.Controls.Add(this.Execute);
            this.Controls.Add(this.SearchAttTextBox);
            this.Controls.Add(this.SearchAtt);
            this.Controls.Add(this.ColName);
            this.Controls.Add(this.ChooseFunctionLabel);
            this.Controls.Add(this.FunctionsList);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.Name = "ScalarFunctionGeneration";
            this.Text = "Scalar Function Generation Module";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.StringConc)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox FunctionsList;
        private System.Windows.Forms.Label ChooseFunctionLabel;
        private System.Windows.Forms.Label ColName;
        private System.Windows.Forms.Label SearchAtt;
        private System.Windows.Forms.TextBox SearchAttTextBox;
        private System.Windows.Forms.Button Execute;
        private System.Windows.Forms.Button newform;
        private System.Windows.Forms.ComboBox ChosenCol1;
        private System.Windows.Forms.Label ColumName;
        private System.Windows.Forms.DataGridView StringConc;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox ChosenCol2;
        private System.Windows.Forms.ComboBox ChosenTables;
    }
}

