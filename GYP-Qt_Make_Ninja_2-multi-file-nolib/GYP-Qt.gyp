#####################################################################################
# gyp script for building the qt toy program: Numeric Keypad
# written by Chuan Zhang on Jan. 26. 2016
# Project:  NKeyPad
#####################################################################################

{
	'includes': [
		'../QYP-Qt_common/qt_common.gypi',
	],
	'targets': [
	{
		'target_name': 'NKeyPad',
		'type': 'executable',
		'include_dirs': [
			'<(DEPTH)',
			'<(DEPTH)/include',
			'<(DEPTH)/src',
		],
		'sources': [
			'src/main.cpp',
			'include/numerickeypad.cpp',
			'include/numerickeypad.h',
		# [Chuan Zhang, 01/26/2016] before using gyp to produce build files, 
		# always ensure the moc file is generated from the corresponding 
		# header file using moc
			'include/moc_numerickeypad.cpp', 
		],
	}],
}


