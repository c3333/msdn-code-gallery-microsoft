# C++ Windows Shell drag and drop handler (CppShellExtDragDropHandler)
## Requires
- Visual Studio 2010
## License
- MS-LPL
## Technologies
- Windows Shell
## Topics
- Windows Shell
- Drag and Drop
- handler
## Updated
- 07/22/2012
## Description

<h1><span style="font-family:新宋体">C&#43;&#43; Windows Shell Drag and Drop Handler </span>
(<span class="SpellE"><span style="font-family:新宋体">CppShellExtDragDropHandler</span></span>)</h1>
<h2>Introduction</h2>
<p class="MsoNormal"><span style="">The code sample demonstrates creating a Shell drag-and-drop handler with C&#43;&#43;.
</span></p>
<p class="MsoNormal"><span style="">When a user right-clicks a Shell object to drag an object, a context menu is displayed when the user attempts to drop the object. A drag-and-drop handler is a context menu handler that can add items to this context menu.
</span></p>
<p class="MsoNormal"><span style="">The example drag-and-drop handler has the class ID (CLSID): {F574437A-F944-4350-B7E9-95B6C7008029}
</span></p>
<p class="MsoNormal"><span style="">It adds the menu item &quot;Create hard link here&quot; to the context menu. When you right-click a file and drag the file to a directory or a drive or the desktop, a context menu will be displayed with the &quot;Create
 hard link here&quot; menu item. By clicking the menu item, the handler will create a hard link for the dragged file in the dropped location. The name of the link is &quot;Hard link to &lt;source file name&gt;&quot;.
</span></p>
<p class="MsoNormal"><span style="">(A hard link is the file system representation of a file by which more than one path references a single file in the same volume. Any changes to that file are instantly visible to applications that access it through the
 hard links that reference it. For more information about hard links, refer to the MSDN documentation:
</span><span class="MsoHyperlink"><a href="http://msdn.microsoft.com/en-us/library/aa365006.aspx">http://msdn.microsoft.com/en-us/library/aa365006.aspx</a></span><span style="">.)
</span></p>
<h2>Running the Sample</h2>
<p class="MsoNormal"><span style="">The following steps walk through a demonstration of the drag-and-drop handler code sample.
</span></p>
<p class="MsoNormal"><b style=""><span style="font-size:16.0pt; line-height:115%">Step1.</span></b><span style=""> If you are going to use the Shell extension in
<span class="GramE">a</span> x64 Windows system, please configure the Visual C&#43;&#43; project to target 64-bit platforms using project configurations (</span><span class="MsoHyperlink"><a href="http://msdn.microsoft.com/en-us/library/9yb4317s.aspx">http://msdn.microsoft.com/en-us/library/9yb4317s.aspx</a></span><span style="">).
 Only 64-bit extension DLLs can be loaded in the 64-bit Windows Shell. </span></p>
<p class="MsoNormal"><span style="">If the extension is to be loaded in a 32-bit Windows system, please use the default Win32 project configuration.
</span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<b style=""><span style="font-size:16.0pt">Step2.</span></b><span style=""> After you successfully build the sample project in Visual Studio 2010, you will get a DLL: CppShellExtDragDropHandler.dll. Start a command prompt as administrator, navigate to the folder
 that contains the file and enter the command: Regsvr32.exe CppShellExtDragDropHandler.dll. The operation needs the Administrator permission.</span><span style="font-size:9.5pt; font-family:Consolas">
</span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="">The <span class="SpellE">infotip</span> handler is registered successfully if you see a message box saying: &quot;<span class="SpellE">DllRegisterServer</span> in CppShellExtDragDropHandler.dll succeeded.&quot;</span><span style="font-size:9.5pt; font-family:Consolas">
</span></p>
<p class="MsoNormal"><b style=""><span style="font-size:16.0pt; line-height:115%">Step3.</span></b><span style=""> Find a file in the Windows Explorer, right-click the file and drag it to a directory in the same volume. A context menu will be displayed with
 the &quot;Create hard link here&quot; menu item. By clicking the menu item, the handler will create a hard link for the dragged file in the dropped location. The name of the link is &quot;Hard link to &lt;source file name&gt;&quot; . Any changes to the source
 file are instantly visible to applications that access it through the hard link that reference it. If there is already a file with the same name in dropped location, you will see an error message &quot;There is already a file with the same name in this location.&quot;
 prompted by the Windows Shell. </span></p>
<p class="MsoNormal"><span style=""><img src="61858-image.png" alt="" width="493" height="330" align="middle">
</span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<b style=""><span style="font-size:16.0pt">Step4.</span></b><span style=""> In the same command prompt, run the
<span class="GramE">command<span style="">&nbsp; </span>&quot;</span> Regsvr32.exe /u CppShellExtDragDropHandler.dll&quot; to unregister the Shell
<span class="SpellE">infotip</span> handler. The operation needs the Administrator permission.</span><span style="font-size:9.5pt; font-family:Consolas">
</span></p>
<h2>Implementation</h2>
<p class="MsoListParagraph" style="text-indent:-.25in"><b style=""><span style="font-size:12.0pt; line-height:115%"><span style="">1.<span style="font:7.0pt &quot;Times New Roman&quot;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span></span></span></b>Creating and configuring the project.</p>
<p class="MsoNormal"><span style="">In Visual Studio 2010, create a Visual C&#43;&#43; / Win32 / Win32 Project named &quot;<span class="SpellE">CppShellExtDragDropHandler</span>&quot;. In the &quot;Application Settings&quot; page of Win32 Application Wizard, select
 the application type as &quot;DLL&quot; and check the &quot;Empty project&quot; option. After you click the Finish button, an empty Win32 DLL project is created.
</span></p>
<p class="MsoListParagraph" style="text-indent:-.25in"><b style=""><span style="font-size:12.0pt; line-height:115%"><span style="">2.<span style="font:7.0pt &quot;Times New Roman&quot;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span></span></span></b>Implementing a basic Component Object Model (COM) DLL.</p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:9.5pt; font-family:Consolas">Shell extension handlers are all in-process COM objects implemented as DLLs.
</span></p>
<p class="MsoNormal"><span style="">Shell extension handlers are all in-process COM objects implemented as DLLs. Making a basic COM includes implementing
<span class="SpellE">DllGetClassObject</span>, <span class="SpellE">DllCanUnloadNow</span>,
<span class="SpellE">DllRegisterServer</span>, and <span class="SpellE">DllUnregisterServer</span> in (and exporting them from) the DLL, adding a COM class with the basic implementation of the
<span class="SpellE">IUnknown</span> interface, preparing the class factory for your COM class. The relevant files in this code sample are:
</span></p>
<p class="MsoNormal"><span style="font-size:10.0pt; line-height:115%"><span style="">&nbsp;
</span>dllmain.cpp - implements <span class="SpellE">DllMain</span> and the <span class="SpellE">
DllGetClassObject</span>, <span class="SpellE">DllCanUnloadNow</span>, <span class="SpellE">
DllRegisterServer</span>, <span class="SpellE">DllUnregisterServer</span> functions that are necessary for a COM DLL.
</span></p>
<p class="MsoNormal"><span style="font-size:10.0pt; line-height:115%"><span style="">&nbsp;
</span>GlobalExportFunctions.def - exports the <span class="SpellE">DllGetClassObject</span>,
<span class="SpellE">DllCanUnloadNow</span>, <span class="SpellE">DllRegisterServer</span>,
<span class="SpellE">DllUnregisterServer</span> functions from the DLL through <span class="GramE">
the <span style="">&nbsp;</span>module</span>-definition file. You need to pass the .<span class="SpellE">def</span> file to the linker by configuring the Module Definition File property in the project's Property Pages / Linker / Input property page.
</span></p>
<p class="MsoNormal"><span style="font-size:10.0pt; line-height:115%"><span style="">&nbsp;
</span><span class="SpellE">Reg.h</span>/<span class="SpellE">cpp</span> - defines the reusable helper functions to register or unregister in-process COM components in the registry:
<span class="SpellE">RegisterInprocServer</span>, <span class="SpellE">UnregisterInprocServer</span>
</span></p>
<p class="MsoNormal"><span style="font-size:10.0pt; line-height:115%"><span style="">&nbsp;
</span><span class="SpellE">FileDragDropExt.h</span>/<span class="SpellE">cpp</span> - defines the COM class. You can find the basic implementation of the
<span class="SpellE">IUnknown</span> interface in the files. </span></p>
<p class="MsoNormal"><span style="font-size:10.0pt; line-height:115%"><span style="">&nbsp;
</span><span class="SpellE">ClassFactory.h</span>/<span class="SpellE">cpp</span> - defines the class factory for the COM class.
</span></p>
<p class="MsoListParagraph" style="text-indent:-.25in"><b style=""><span style="font-size:12.0pt; line-height:115%"><span style="">3.<span style="font:7.0pt &quot;Times New Roman&quot;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span></span></span></b>Implementing the drag-and-drop handler and registering it.</p>
<p class="MsoNormal">Implementing the drag-and-drop handler: </p>
<p class="MsoNormal">A drag-and-drop handler is a context menu handler that can add items to this context menu. The basic procedure for implementing a drag-and-drop handler is the same as for conventional context menu handlers.
</p>
<p class="MsoNormal">The <span class="SpellE">FileDragDropExt.h</span>/<span class="SpellE">cpp</span> files define a drag-and-drop handler. The drag-and-drop handler must implement the
<span class="SpellE">IShellExtInit</span> and <span class="SpellE">IContextMenu</span> interfaces.
</p>
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>C&#43;&#43;</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span>
</div>
<span class="hidden">cplusplus</span>

<pre id="codePreview" class="cplusplus">


class FileDragDropExt
: public IShellExtInit,
public IContextMenu


{


public:


   
// IShellExtInit


   
IFACEMETHODIMP Initialize(LPCITEMIDLIST pidlFolder, LPDATAOBJECT pDataObj,
HKEY hKeyProgID);






   
// IContextMenu


   
IFACEMETHODIMP QueryContextMenu(HMENU hMenu, UINT indexMenu, UINT idCmdFirst, UINT idCmdLast, UINT uFlags);


   
IFACEMETHODIMP InvokeCommand(LPCMINVOKECOMMANDINFO pici);


   
IFACEMETHODIMP GetCommandString(UINT_PTR idCommand, UINT uFlags, UINT *pwReserved, LPSTR pszName, UINT cchMax);


};



</pre>
</div>
</div>
<div class="endscriptcode">&nbsp;</div>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span class="GramE"><span style="font-size:10.0pt; font-family:Consolas; color:blue">class</span></span><span style="font-size:10.0pt; font-family:Consolas">
<span class="SpellE">FileDragDropExt</span> : <span style="color:blue">public</span>
<span class="SpellE">IShellExtInit</span>, <span style="color:blue">public</span>
<span class="SpellE">IContextMenu</span> </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas">{ </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span class="GramE"><span style="font-size:10.0pt; font-family:Consolas; color:blue">public</span></span><span style="font-size:10.0pt; font-family:Consolas">:
</span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;
</span><span style="color:green">// <span class="SpellE">IShellExtInit</span></span>
</span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;
</span>IFACEMETHODIMP <span class="GramE">Initialize(</span>LPCITEMIDLIST <span class="SpellE">
pidlFolder</span>, LPDATAOBJECT <span class="SpellE">pDataObj</span>, HKEY <span class="SpellE">
hKeyProgID</span>); </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"></span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;
</span><span style="color:green">// <span class="SpellE">IContextMenu</span></span>
</span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;
</span>IFACEMETHODIMP <span class="SpellE"><span class="GramE">QueryContextMenu</span></span><span class="GramE">(</span>HMENU
<span class="SpellE">hMenu</span>, UINT <span class="SpellE">indexMenu</span>, UINT
<span class="SpellE">idCmdFirst</span>, UINT <span class="SpellE">idCmdLast</span>, UINT
<span class="SpellE">uFlags</span>); </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;
</span>IFACEMETHODIMP <span class="SpellE"><span class="GramE">InvokeCommand</span></span><span class="GramE">(</span>LPCMINVOKECOMMANDINFO
<span class="SpellE">pici</span>); </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;
</span>IFACEMETHODIMP <span class="SpellE"><span class="GramE">GetCommandString</span></span><span class="GramE">(</span>UINT_PTR
<span class="SpellE">idCommand</span>, UINT <span class="SpellE">uFlags</span>, UINT *<span class="SpellE">pwReserved</span>, LPSTR
<span class="SpellE">pszName</span>, UINT <span class="SpellE">cchMax</span>);
</span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas">}; </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span class="GramE"><b style="">3.1</b><span style="">&nbsp; </span>Implementing</span>
<span class="SpellE">IShellExtInit</span>.<span style="font-size:9.5pt; font-family:Consolas">
</span></p>
<p class="MsoNormal"><span style="">&nbsp; </span>After the drag-and-drop extension COM object is instantiated,
<span class="GramE">the <span style="">&nbsp;</span><span class="SpellE">IShellExtInit</span></span>::Initialize method is called. Among the parameters of the method,
<span class="SpellE">pidlFolder</span> is the PIDL of the folder where the files were dropped.
<span class="GramE">you</span> can get the directory from the PIDL by calling <span class="SpellE">
SHGetPathFromIDList</span>. </p>
<p class="MsoNormal"><span style="">&nbsp; </span><span class="SpellE"><span class="GramE">pDataObj</span></span> is an
<span class="SpellE">IDataObject</span> interface pointer through which we retrieve the names of the files being dragged.
</p>
<p class="MsoNormal"><span style="">&nbsp; </span>If any value other than S_OK is returned from
<span class="SpellE">IShellExtInit</span>::Initialize, the drag-and-drop menu item will not be used.
</p>
<p class="MsoNormal"><span style="">&nbsp; </span>In the code sample, the <span class="SpellE">
FileDragDropExt</span>::Initialize method retrieves the target directory and saves the directory path in the member
<span class="SpellE">variable<span class="GramE">:m</span>_szTargetDir</span>.</p>
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>C&#43;&#43;</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span>
</div>
<span class="hidden">cplusplus</span>

<pre id="codePreview" class="cplusplus">


   
// Get the directory where the file is dropped
to.


   
if (!SHGetPathFromIDList(pidlFolder, this-&gt;m_szTargetDir))


   
{


              return E_FAIL;


   
}





</pre>
</div>
</div>
<div class="endscriptcode">&nbsp;</div>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;
</span><span style="color:green">// Get the directory where the file is dropped to.</span>
</span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;
</span><span class="GramE"><span style="color:blue">if</span></span> (!<span class="SpellE">SHGetPathFromIDList</span>(<span class="SpellE">pidlFolder</span>,
<span style="color:blue">this</span>-&gt;<span class="SpellE">m_szTargetDir</span>))
</span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;
</span>{ </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span><span class="GramE"><span style="color:blue">return</span></span> E_FAIL;
</span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;
</span>} </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:&quot;Courier New&quot;"></span></p>
<p class="MsoNormal"><span style="">&nbsp; </span>It also enumerates the selected files and folders. If only *one* file is dragged, and the file is not a directory considering hard links do not work for directories, the method stores the file name for later
 use and returns S_OK to proceed. </p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<b style="">3.2</b> Implementing <span class="SpellE">IContextMenu</span>.<span style="font-size:9.5pt; font-family:Consolas">
</span></p>
<p class="MsoNormal">After <span class="SpellE">IPersistFile</span> is queried, the Shell queries the
<span class="SpellE">IQueryInfo</span> <span class="GramE">interface<span style="">&nbsp;
</span>and</span> the <span class="SpellE">GetInfoTip</span> method is called. <span class="SpellE">
GetInfoTip</span> has an out parameter <span class="SpellE">ppwszTip</span> of the type LPWSTR * which
<span class="SpellE">recieves</span> the address of the tool <span class="GramE">
tip<span style="">&nbsp; </span>buffer</span>. Please note that the memory pointed by *<span class="SpellE">ppwszTip</span> must be
<span class="GramE">allocated<span style="">&nbsp; </span>by</span> calling <span class="SpellE">
CoTaskMemAlloc</span>. Shell knows to call <span class="SpellE">CoTaskMemFree</span> to free the memory when the info tip is no longer needed.</p>
<p class="MsoNormal">In this code sample, the example <span class="SpellE">infotip</span> is composed of the file path and the count of text lines.</p>
<p class="MsoNormal">After <span class="SpellE">IShellExtInit</span>::Initialize returns S_OK,
<span class="GramE">the <span style="">&nbsp;</span><span class="SpellE">IContextMenu</span></span>::<span class="SpellE">QueryContextMenu</span> method is called to obtain the menu item or items that the drag-and-drop extension will add. The
<span class="SpellE">QueryContextMenu</span> implementation is fairly straightforward. The drag-and-drop extension adds its menu items using the
<span class="SpellE">InsertMenuItem</span> or similar functions. The menu command identifiers must be greater than or equal to
<span class="SpellE">idCmdFirst</span> and must be less than <span class="SpellE">
idCmdLast</span>. <span class="SpellE">QueryContextMenu</span> must return the greatest numeric identifier added to the menu plus one. The best way to assign menu command identifiers is to start at zero and work up in sequence. If the drag-and-drop extension
 does not need to add any items to the menu, it should simply return zero from <span class="SpellE">
QueryContextMenu</span>. </p>
<p class="MsoNormal"><span style="">&nbsp; </span>In this code sample, we insert the menu item &quot;Create hard link here&quot;.
</p>
<p class="MsoNormal"><span style="">&nbsp; </span><span class="SpellE">IContextMenu</span>::<span class="SpellE">GetCommandString</span> is called to retrieve textual data for the menu item, such as help text to be displayed for the menu item. In this
 drag-and-drop handler example, we do not need the help string or verb string for the command, so we simply return E_NOTIMPL from
<span class="SpellE">GetCommandString</span>.<span style="">&nbsp; </span></p>
<p class="MsoNormal"><span style="">&nbsp; </span><span class="SpellE">IContextMenu</span>::<span class="SpellE">InvokeCommand</span> is called when one of the menu items installed by the extension is selected. The handler establishes a hard link between
 the dragged file and a new file in the dropped location in response to the &quot;Create hard link here&quot; command.
</p>
<p class="MsoListParagraph" style="text-indent:-.25in"><b style=""><span style="font-size:12.0pt; line-height:115%"><span style="">4.<span style="font:7.0pt &quot;Times New Roman&quot;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span></span></span></b>Registration and <span class="SpellE">Unregistration</span>.</p>
<p class="MsoNormal">Registering the <span class="SpellE">handler<span class="GramE">:The</span></span> CLSID of the handler is declared at the beginning of dllmain.cpp.</p>
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>C&#43;&#43;</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span>
</div>
<span class="hidden">cplusplus</span>

<pre id="codePreview" class="cplusplus">


//
{F574437A-F944-4350-B7E9-95B6C7008029}


const CLSID CLSID_FileDragDropExt
= 


{ 0xF574437A, 0xF944, 0x4350, { 0xB7, 0xE9, 0x95,
0xB6, 0xC7, 0x00, 0x80, 0x29 } };





</pre>
</div>
</div>
<div class="endscriptcode">&nbsp;</div>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas; color:green">// {F574437A-F944-4350-B7E9-95B6C7008029}</span><span style="font-size:10.0pt; font-family:Consolas">
</span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span class="SpellE"><span class="GramE"><span style="font-size:10.0pt; font-family:Consolas; color:blue">const</span></span></span><span style="font-size:10.0pt; font-family:Consolas"> CLSID
<span class="SpellE">CLSID_FileDragDropExt</span> = </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas">{ 0xF574437A, 0xF944, 0x4350, { 0xB7, 0xE9, 0x95, 0xB6, 0xC7, 0x00, 0x80, 0x29 } };
</span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:9.5pt; font-family:Consolas; color:green"></span></p>
<p class="MsoNormal">When you write your own handler, you must create a new CLSID by using the &quot;Create GUID&quot; tool in the Tools menu, and specify the CLSID value here.
</p>
<p class="MsoNormal">Drag-and-drop handlers are typically registered under the following
<span class="SpellE">subkey</span>: </p>
<p class="MsoNormal"><span style="">&nbsp;</span>HKEY_CLASSES_ROOT\Directory\<span class="SpellE">shellex</span>\<span class="SpellE">DragDropHandlers</span>\
</p>
<p class="MsoNormal">In some cases, you also need to register it under HKCR\Folder to handle drops on the desktop, and HKCR\Drive to handle drops in root directories.
</p>
<p class="MsoNormal">The registration of the drag-and-drop handler is implemented in the
<span class="SpellE">DllRegisterServer</span> function of dllmain.cpp. <span class="SpellE">
DllRegisterServer</span> first calls the <span class="SpellE">RegisterInprocServer</span> function in
<span class="SpellE">Reg.h</span>/<span class="SpellE">cpp</span> to register the COM component. Next, it calls
<span class="SpellE">RegisterShellExtDragDropHandler</span> to register the drag-and-drop handler under HKEY_CLASSES_ROOT\Directory\<span class="SpellE">shellex</span>\<span class="SpellE">DragDropHandlers</span>\, HKEY_CLASSES_ROOT\Folder\<span class="SpellE">shellex</span>\<span class="SpellE">DragDropHandlers</span>\,
 and HKEY_CLASSES_ROOT\Drive\<span class="SpellE">shellex</span>\<span class="SpellE">DragDropHandlers</span>\.
</p>
<p class="MsoNormal">The following keys and values are added in the registration process of the sample handler.</p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; color:black"><span style="">&nbsp;&nbsp;&nbsp; </span>
</span><span style="font-size:10.0pt; font-family:Consolas">HKCR </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;
</span>{ </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span><span class="SpellE">NoRemove</span> CLSID </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span>{ </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span><span class="SpellE">ForceRemove</span> {F574437A-F944-4350-B7E9-95B6C7008029} =
</span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span><span class="GramE">s</span> '<span class="SpellE">CppShellExtDragDropHandler.FileDragDropExt</span> Class'
</span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span>{ </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;
</span><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span>InprocServer32 = s '&lt;Path of CppShellExtDragDropHandler.DLL file&gt;'
</span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span>{ </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span><span class="SpellE"><span class="GramE">val</span></span> <span class="SpellE">
ThreadingModel</span> = s 'Apartment' </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span>} </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span>} </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span>} </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span><span class="SpellE">NoRemove</span> Directory </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span>{ </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span><span class="SpellE">NoRemove</span> <span class="SpellE">shellex</span>
</span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span>{ </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span><span class="SpellE">NoRemove</span> <span class="SpellE">DragDropHandlers</span>
</span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span>{ </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span>{F574437A-F944-4350-B7E9-95B6C7008029} = </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span><span class="GramE">s</span> '<span class="SpellE">CppShellExtDragDropHandler.FileDragDropExt</span>'
</span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span>} </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span>} </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span>} </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span><span class="SpellE">NoRemove</span> Folder </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span>{ </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span><span class="SpellE">NoRemove</span> <span class="SpellE">shellex</span>
</span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span>{ </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span><span class="SpellE">NoRemove</span> <span class="SpellE">DragDropHandlers</span>
</span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span>{ </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span>{F574437A-F944-4350-B7E9-95B6C7008029} = </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span><span class="GramE">s</span> '<span class="SpellE">CppShellExtDragDropHandler.FileDragDropExt</span>'
</span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span>} </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span>} </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span>} </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span><span class="SpellE">NoRemove</span> Drive </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span>{ </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span><span class="SpellE">NoRemove</span> <span class="SpellE">shellex</span>
</span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span>{ </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span><span class="SpellE">NoRemove</span> <span class="SpellE">DragDropHandlers</span>
</span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span>{ </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span>{F574437A-F944-4350-B7E9-95B6C7008029} = </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp; </span>
<span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span><span class="GramE">s</span> '<span class="SpellE">CppShellExtDragDropHandler.FileDragDropExt</span>'
</span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span>} </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span>} </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</span>} </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:Consolas"><span style="">&nbsp;&nbsp;&nbsp;
</span>} </span></p>
<p class="MsoNormal" style="margin-bottom:0in; margin-bottom:.0001pt; line-height:normal; text-autospace:none">
<span style="font-size:10.0pt; font-family:&quot;Courier New&quot;"></span></p>
<p class="MsoNormal">The <span class="SpellE">unregistration</span> is implemented in the
<span class="SpellE">DllUnregisterServer</span> function of dllmain.cpp. It removes the HKCR\CLSID<span class="GramE">\{</span>&lt;CLSID&gt;} key and the {&lt;CLSID&gt;} key under HKCR\Directory\<span class="SpellE">shellex</span>\<span class="SpellE">ContextMenuHandlers</span>,
 HKCR\Folder\<span class="SpellE">shellex</span>\<span class="SpellE">ContextMenuHandlers</span>, and HKCR\Drive\<span class="SpellE">shellex</span>\<span class="SpellE">ContextMenuHandlers</span>.
</p>
<h2>More Information<span style="font-family:新宋体"> </span></h2>
<p class="MsoNormal"><span style="">MSDN: Creating Drag-and-Drop Handlers </span>
</p>
<p class="MsoNormal"><span class="MsoHyperlink"><a href="http://msdn.microsoft.com/en-us/library/bb776881.aspx%23dragdrop">http://msdn.microsoft.com/en-us/library/bb776881.aspx#dragdrop</a></span><u><span style="color:blue">
</span></u></p>
<p class="MsoNormal"><span style="">The Complete Idiot's Guide to Writing Shell Extensions - Part IV
</span></p>
<p class="MsoNormal"><span class="MsoHyperlink"><a href="http://www.codeproject.com/KB/shell/shellextguide4.aspx">http://www.codeproject.com/KB/shell/shellextguide4.aspx</a></span><u><span style="color:blue">
</span></u></p>
<hr>
<div><a href="http://go.microsoft.com/?linkid=9759640" style="margin-top:3px"><img alt="" src="http://bit.ly/onecodelogo">
</a></div>
