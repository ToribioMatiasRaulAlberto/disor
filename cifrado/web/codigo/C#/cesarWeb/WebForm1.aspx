<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="cesarWeb.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">
        #TextArea1 {
            margin-top: 0px;
            height: 64px;
            width: 278px;
            top: 11px;
            left: 14px;
        }
        #TextArea2 {
            height: 72px;
            width: 292px;
            top: 24px;
            left: 8px;
        }
        #TextArea3 {
            height: 53px;
            width: 286px;
            top: 13px;
            left: 9px;
        }
        #Text3 {
            top: 4px;
            left: 8px;
            width: 241px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
    </div>
        <section>
            <p>
            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            Texto a cifrar:<input id="Text3" style="position: relative" type="text" /></p>
        </section>
        
        <section style="border: medium solid #000000; width: 315px; height: 135px">

            Cifrado Cesar<br />
            Desplazamiento:<input id="Text1" type="number" value="0" /><textarea id="TextArea1" name="S1" style="position: relative"></textarea></section>
        <section style="border: medium solid #000000; width: 310px; height: 134px; position: relative; top: -142px; left: 328px;">

            Tranposicion inversa:<br />
            <textarea id="TextArea2" name="S2" style="position: relative"></textarea></section>
        <section style="border-style: solid; border-width: medium; width: 310px; height: 127px; position: relative; top: -124px; left: 175px;">

            Transposicion inv. agrupacion<br />
            agrupacion:<input id="Text2" type="number" value="0" /><textarea id="TextArea3" name="S3" style="position: relative"></textarea></section>
    </form>
    <p>
        &nbsp;</p>
</body>
</html>
