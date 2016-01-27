#####################################################################################
# gyp script for building the qt toy program: Numeric Keypad
# written by Chuan Zhang on Jan. 26. 2016
# Project:  NKeyPad
#####################################################################################

{
	'includes': [
		'../GYP-Qt_common/qt_common.gypi',
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
		'conditions': [
			['OS == "linux"', {
				'sources': [
					'include/numerickeypad.cpp',
					'include/numerickeypad.h',
					'src/main.cpp',
					'<!(moc include/numerickeypad.h -o include/moc_numerickeypad.cpp && echo include/moc_numerickeypad.cpp)',
				],
			}],
		],
	}],
}


