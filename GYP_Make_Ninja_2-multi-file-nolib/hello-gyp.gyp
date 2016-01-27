{
	'targets': [
	{
		'target_name': 'hello-gyp',
		'type': 'executable',
		'sources': [
			'src/main.cpp',
			'include/print.cpp',
		],
		'conditions': [
			['OS=="linux"', {
				'defines': [
					'LINUX_DEFINE',
				],
			}],
		],
	}],
}
