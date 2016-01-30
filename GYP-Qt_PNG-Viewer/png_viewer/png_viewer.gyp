

{
	'includes': [
		'../../GYP-Qt_common/qt_common.gypi',
	],
	'targets': [
		{
			'target_name': 'png_viewer',
			'type': 'executable',
			'sources': [
				'main.cpp',
				'png_viewer.cpp',
				'png_viewer.h',
				'<!(moc png_viewer.h -o moc_png_viewer.cpp && echo moc_png_viewer.cpp)',
			],
		},
	],
}

