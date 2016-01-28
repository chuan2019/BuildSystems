{
	'targets': [
		{
			'target_name': 'hello-static',
			'type': 'static_library',
			'include_dirs': [
				'include',
			],
			'sources': [
				'include/print.cpp',
				'include/print.h',
			],
		},
		{
			'target_name': 'hello-shared',
			'type': 'shared_library',
			'include_dirs': [
				'include',
			],
			'sources': [
				'include/print.cpp',
				'include/print.h',
			],
			'cflags': [
				'-fPIC',
			],
		},
		{
			'target_name': 'hello-gyp',
			'type': 'executable',
			'include_dirs': [
				'<(DEPTH)',
				'<(DEPTH)/include',
			],
			'dependencies': [
				'hello-static',
				#'hello-shared',
			],
			'sources': [
				'src/main.cpp',
				'include/print.h',
			],
		},
	],
}

