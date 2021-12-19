/*
2. Suffix Array Re-construction
https://open.kattis.com/problems/suffixarrayreconstruction
*/

#include<iostream>
#include<string>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, s;
		cin >> n >> s;
		string out(n, '$');

		bool conflict = false;
		while ( s-- ) {
			int p;
			string suff;
			cin >> p >> suff;
			p--;

			bool asterisk = false;
			for ( int i = p; i < n; ++i ) {
				if ( suff[i - p] == '*' ) {
					asterisk = true;
					break;
				}
				if ( out[i] != '$' && out[i] != suff[i - p] )
					conflict = true;
				else out[i] = suff[i - p];
			}

			if ( asterisk ) {
				for ( int i = n - 1, j = suff.size() - 1; j >= 0; --j, --i ) {
					if ( suff[j] == '*' )
						break;
					else if ( out[i] != '$' && out[i] != suff[j] )
						conflict = true;
					else out[i] = suff[j];
				}
			}
		}

		for ( int i = 0; i < n; ++i )
			conflict = conflict || out[i] == '$';

		if ( conflict )
			cout << "IMPOSSIBLE\n";
		else cout << out << '\n';
	}

	cout << flush;

	return 0;
}