# CSC1300StylizedHeaderGen
A Notepad++ plugin that generates a stylized header a the top of your currently open file in notepad++ for CSC1300

Installation
---------------------------------
1. Download the version of the plugin you need for your PC from the "releases" page (64 bit or 32 bit).

2. Open your Notepad++ installation folder (C:\Program Files\Notepad++ by default).

3. Open the plugins folder contained within your Notepad++ folder.

4. Extract the .zip file you downloaded into this folder (you should now have a folder called CSC1300HeaderGen with a .dll file within it; if not, make it so).

5. Launch Notepad++. "CSC1300StylizedHeaderGen" should now be listed under the "plugins" tab at the top of the screen. You can now activate the plugin by selecting it here, which will replace whatever text is within your currently open document with the generated header.

6. (optional) Unbind Alt + H from your keyboard shortcuts by going into "Settings" -> "Shortcut Mapper" and searching for the shortcut. You can now activate the plugin at any time by pressing Alt + H on your keyboard.

End Notes
--------------------------------
1. I claim no credit for any of the code of this plugin. All I wrote was the code that processes the currently open file and time, creates a character string out of this, and then sends the processed character string on to the message handler (as well as the functions necessary to make that happen properly). This code and everything else is now public domain under the GNU General Public License v2.0 (the details of which can be found in this repository).

2. This plugin will use my name in the "Author" section of the comment header it creates. You can simply change this after the plugin runs, but I invite you to modify the code and recompile to suit your needs.
